{# Copyright (c) Pelagicore AB 2016 #}
{% set class = 'Qml{0}'.format(interface) %}
/****************************************************************************
** This is an auto-generated file.
** Do not edit! All changes made to it will be lost.
****************************************************************************/

#pragma once

#include <QtCore>

#include "qml{{module.module_name|lower}}module.h"

class {{class}} : public QObject
{
    Q_OBJECT
{% for property in interface.properties %}
    Q_PROPERTY({{property|returnType}} {{property}} READ {{property}} {%if not property.is_readonly%}WRITE set{{property|upperfirst}} {%endif%}NOTIFY {{property}}Changed)
{% endfor %}

public:
    {{class}}(QObject *parent=0);

    static void registerQmlTypes(const QString& uri, int majorVersion=1, int minorVersion=0);

public Q_SLOTS:
{% for operation in interface.operations %}    
    {{operation|returnType}} {{operation}}({{operation.parameters|map('parameterType')|join(', ')}});
{%- endfor %}

public:
{% for property in interface.properties %}
    void set{{property|upperfirst}}({{ property|parameterType }});
    {{property|returnType}} {{property}}() const;

{% endfor %}
Q_SIGNALS:
{% for property in interface.properties %}
    void {{property}}Changed({{property|parameterType}});
{% endfor %}

private:
{% for property in interface.properties %}
    {{property|returnType}} m_{{property}};
{% endfor %}
};
