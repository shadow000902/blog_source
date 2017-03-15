{% if theme.algolia_search.enable %}
  {% include '../_components/algolia-search/dom.swig' %}
{% elseif theme.swiftype_key %}
  {% include 'search/swiftype.swig' %}
{% elseif theme.tinysou_Key %}
  {% include 'search/tinysou.swig' %}
{% elseif theme.local_search.enable %}
  {% include 'search/localsearch.swig' %}
<!-- 增加下面语句 -->
{% elseif theme.algolia_search %}
  {% include 'search/algolia.swig' %}
<!-- 增加结束 -->
{% endif %}
