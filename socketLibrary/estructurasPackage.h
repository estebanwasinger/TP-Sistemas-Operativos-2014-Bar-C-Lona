<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<!-- saved from url=(0264)https://docs.google.com/viewer?pid=explorer&srcid=0B--MFC48AFZiaVNVbVk5NjVrcWJwUm5ySzg1bTVvZ3Boc0Fv&docid=40137e45a34faf08f6461849a16891bf%7C7d8d77647de03e113d972c9c08bee823&chan=EQAAAH0aw3sahfpagTIgvH9I/9SLYt88h8yB7MTFpbZj80UP&a=v&rel=rar;r14;estructurasPackage.h -->
<html><head><meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<script type="text/javascript">
(function(){(function(){function e(a){this.t={};this.tick=function(a,c,b){var d=void 0!=b?b:(new Date).getTime();this.t[a]=[d,c];if(void 0==b)try{window.console.timeStamp("CSI/"+a)}catch(e){}};this.tick("start",null,a)}var a;window.performance&&(a=window.performance.timing);var f=a?new e(a.responseStart):new e;window.jstiming={Timer:e,load:f};if(a){var c=a.navigationStart,d=a.responseStart;0<c&&d>=c&&(window.jstiming.srt=d-c)}if(a){var b=window.jstiming.load;0<c&&d>=c&&(b.tick("_wtsrt",void 0,c),b.tick("wtsrt_",
"_wtsrt",d),b.tick("tbsd_","wtsrt_"))}try{a=null,window.chrome&&window.chrome.csi&&(a=Math.floor(window.chrome.csi().pageT),b&&0<c&&(b.tick("_tbnd",void 0,window.chrome.csi().startE),b.tick("tbnd_","_tbnd",c))),null==a&&window.gtbExternal&&(a=window.gtbExternal.pageT()),null==a&&window.external&&(a=window.external.pageT,b&&0<c&&(b.tick("_tbnd",void 0,window.external.startE),b.tick("tbnd_","_tbnd",c))),a&&(window.jstiming.pt=a)}catch(g){}})();})();
</script>

<title>estructurasPackage.h</title>
<style type="text/css">
    

    
    html>body .goog-inline-block {
      display: -moz-inline-box; 
      display: inline-block; 
    }

    
    .goog-inline-block {
      position: relative;
      display: inline-block;
    }

    
    * html .goog-inline-block {
      display: inline;
    }

    
    *:first-child+html .goog-inline-block {
      display: inline;
    }
  </style>

<style type="text/css">
    
    .goog-custom-button {
      background:
        #ddd
        repeat-x scroll left top;
      cursor: pointer;
      
      -moz-user-select: none;
    }

    .goog-custom-button-active {
      background-color: #bbb !important;
      background-position: left bottom !important;
    }

    .goog-custom-button-disabled {
      cursor: default !important;
      color: #888;
    }

    .goog-custom-button-outer-box, .goog-custom-button-inner-box {
      border-color: #bbb;
      border-style: solid;
      vertical-align: top;
    }

    .goog-custom-button-outer-box {
      border-width: 1px 0pt;
      margin: 0pt;
      padding: 0pt;
    }

    .goog-custom-button-inner-box {
      border-width: 0pt 1px;
      margin: 0pt -1px;
    }

    
    * html .goog-custom-button-inner-box {
      
        left: -1px;
      
    }

    
    

    
    *:first-child+html .goog-custom-button-inner-box {
      
        left: -1px;
      
    }

    
    
  </style>
<style type="text/css">
    .goog-toolbar {
      background: #f5f5f5;
      border-top: 1px solid #e5e5e5;
      border-bottom: 1px solid #ebebeb;
      outline: 0;
      padding: 8px 0 4px 0;
      margin-bottom: 0;
      position: relative;
      zoom: 1;
    }

    .goog-toolbar-button, .goog-toolbar-menu-button {
      background: 0;
      border-color: transparent;
      -webkit-border-radius: 2px;
      -moz-border-radius: 2px;
      border-radius: 2px;
      border-style: solid;
      border-width: 1px;
      outline: none;
      margin: 4px 0 0 -1px;
      padding: 0;
      height: 24px;
      color: #444;
      line-height: 24px;
      list-style: none;
      font-size: 11px;
      font-weight: bold;
      text-decoration: none;
      vertical-align: middle;
      cursor: default;
      -webkit-user-select: none;
      -moz-user-select: none;
      user-select: none;
      -webkit-transition: all 0.218s;
      -moz-transition: all 0.218s;
      -o-transition: all 0.218s;
      transition: all 0.218s;
    }

    .goog-toolbar-button-outer-box, .goog-toolbar-menu-button-inner-box,
    .goog-toolbar-button-inner-box .goog-toolbar-menu-button-outer-box {
      border: 0;
      vertical-align: top;
    }

    .goog-toolbar-button-outer-box, .goog-toolbar-menu-button-outer-box {
      margin: 0;
      padding: 0;
    }

    .goog-toolbar-button-inner-box, .goog-toolbar-menu-button-inner-box {
      padding: 0 2px;
    }

    .goog-toolbar-button-hover, .goog-toolbar-button-active,
    .goog-toolbar-button-checked, .goog-toolbar-button-selected {
      color: #333;
      padding: 0;
    }

    .goog-toolbar-button-focused,
    .goog-toolbar-button-hover,
    .goog-toolbar-menu-button-hover {
      color: #333;
      -webkit-transition: all 0.0s;
      -moz-transition: all 0.0s;
      -o-transition: all 0.0s;
      transition: all 0.0s;
    }

    .goog-toolbar-button-focused {
      border-color: #a1badf;
    }

    .goog-toolbar-button-hover,
    .goog-toolbar-menu-button-hover {
      border-color: #c6c6c6 !important;
    }

    .goog-toolbar-menu-button-open {
      color: #333;
    }

    .goog-toolbar-button-focused, .goog-toolbar-button-hover,
    .goog-toolbar-menu-button-hover {
      background-color: #f8f8f8;
      background-image: -webkit-linear-gradient(top, #f8f8f8, #f1f1f1);
      background-image: -moz-linear-gradient(top, #f8f8f8, #f1f1f1);
      background-image: -ms-linear-gradient(top, #f8f8f8, #f1f1f1);
      background-image: -o-linear-gradient(top, #f8f8f8, #f1f1f1);
      background-image: linear-gradient(top, #f8f8f8, #f1f1f1);
      -webkit-box-shadow: 0 1px 1px rgba(0, 0, 0, 0.1);
      -moz-box-shadow: 0 1px 1px rgba(0, 0, 0, 0.1);
      box-shadow: 0 1px 1px rgba(0, 0, 0, 0.1);
    }

    .goog-toolbar-button-active, .goog-toolbar-menu-button-active {
      background-color: #f6f6f6;
      background-image: -webkit-linear-gradient(top, #f6f6f6, #f1f1f1);
      background-image: -moz-linear-gradient(top, #f6f6f6, #f1f1f1);
      background-image: -ms-linear-gradient(top, #f6f6f6, #f1f1f1);
      background-image: -o-linear-gradient(top, #f6f6f6, #f1f1f1);
      background-image: linear-gradient(top, #f6f6f6, #f1f1f1);
      border-color: #c6c6c6;
      -webkit-box-shadow: inset 0 1px 2px rgba(0, 0, 0, 0.1);
      -moz-box-shadow: inset 0 1px 2px rgba(0, 0, 0, 0.1);
      box-shadow: inset 0 1px 2px rgba(0, 0, 0, 0.1);
    }

    .goog-toolbar-button-selected, .goog-toolbar-button-checked,
    .goog-toolbar-menu-button-open {
      background-color: #eee;
      background-image: -webkit-linear-gradient(top, #eee, #e0e0e0);
      background-image: -moz-linear-gradient(top, #eee, #e0e0e0);
      background-image: -ms-linear-gradient(top, #eee, #e0e0e0);
      background-image: -o-linear-gradient(top, #eee, #e0e0e0);
      background-image: linear-gradient(top, #eee, #e0e0e0);
      -webkit-box-shadow: inset 0 1px 2px rgba(0, 0, 0, 0.1);
      -moz-box-shadow: inset 0 1px 2px rgba(0, 0, 0, 0.1);
      box-shadow: inset 0 1px 2px rgba(0, 0, 0, 0.1);
      border-color: #ccc;
    }

    .goog-toolbar-button-disabled, .goog-toolbar-menu-button-disabled {
      color: #333 !important;
      opacity: 0.3;
      -moz-opacity: 0.3;
      filter: alpha(opacity=30);
    }

    .goog-toolbar-button-collapse-right,
    .goog-toolbar-button-collapse-right .goog-toolbar-button-outer-box,
    .goog-toolbar-button-collapse-right .goog-toolbar-button-inner-box {
      margin-right: 0;
    }

    .goog-toolbar-button-collapse-left,
    .goog-toolbar-button-collapse-left .goog-toolbar-button-outer-box,
    .goog-toolbar-button-collapse-left .goog-toolbar-button-inner-box {
      margin-left: 0;
    }

    .goog-toolbar-button-inner-box, .goog-toolbar-menu-button-inner-box {
      height: 23px;
      padding: 0 5px;
    }

    .goog-toolbar-menu-button .goog-toolbar-menu-button-outer-box
    .goog-toolbar-menu-button-inner-box, .goog-toolbar-button
    .goog-toolbar-menu-button-outer-box .goog-toolbar-menu-button-inner-box {
      margin: 0 2px;
    }

    .goog-toolbar-button+div.docs-toolbar-small-separator,
    .docs-toolbar-small-separator+div.goog-toolbar-button,
    .docs-toolbar-small-separator+div[class=goog-toolbar-menu-button]
    [class~=goog-toolbar-select] {
      margin-left: 12px;
    }

    .docs-toolbar-small-separator+div.goog-toolbar-select {
      margin-left: -3px;
    }

    .goog-toolbar-button .docs-icon, .goog-toolbar-menu-button .docs-icon {
      opacity: .55;
    }

    .goog-toolbar-button-hover .docs-icon,
    .goog-toolbar-button-selected .docs-icon,
    .goog-toolbar-button-checked .docs-icon,
    .goog-toolbar-menu-button-hover .docs-icon,
    .goog-toolbar-menu-button-selected .docs-icon,
    .goog-toolbar-menu-button-checked .docs-icon {
      opacity: 0.9;
    }

    .goog-toolbar-button-active .docs-icon,
    .goog-toolbar-menu-button-open .docs-icon {
      opacity: 1.0;
    }
  </style>
<style type="text/css">
    
    .goog-custom-button {
      margin: 2px;
      border: 0;
      padding: 0;
      font: normal Tahoma, Arial, sans-serif;
      color: #000;
      background: #ddd
        url("//www.gstatic.com/docs/gview/images/button_bg.png")
        repeat-x top left;
      text-decoration: none;
      list-style: none;
      vertical-align: middle;
      cursor: default;
      outline: none;
    }

    
    .goog-custom-button-outer-box,
    .goog-custom-button-inner-box {
      border-style: solid;
      border-color: #aaa;
      vertical-align: top;
    }

    .goog-custom-button-outer-box {
      margin: 0;
      border-width: 1px 0;
      padding: 0;
    }

    .goog-custom-button-inner-box {
      margin: 0 -1px;
      border-width: 0 1px;
      padding: 3px 4px;
      
      white-space: nowrap;
    }

    
    * html .goog-custom-button-inner-box {
      
      left: -1px;
    }

    
    * html .goog-custom-button-rtl .goog-custom-button-outer-box {
      left: -1px;
    }

    * html .goog-custom-button-rtl .goog-custom-button-inner-box {
      left: 0;
    }

    
    *:first-child+html .goog-custom-button-inner-box {
      
      left: -1px;
    }

    
    *:first-child+html .goog-custom-button-rtl .goog-custom-button-inner-box {
      left: 1px;
    }

    
    ::root .goog-custom-button,
    ::root .goog-custom-button-outer-box {
      
      line-height: 0;
    }

    ::root .goog-custom-button-inner-box {
      
      line-height: normal;
    }

    
    .goog-custom-button-disabled {
      background-image: none !important;
      opacity: 0.4;
      -moz-opacity: 0.4;
      filter: alpha(opacity=40);
    }

    .goog-custom-button-disabled .goog-custom-button-outer-box,
    .goog-custom-button-disabled .goog-custom-button-inner-box {
      color: #333 !important;
      border-color: #999 !important;
    }

    
    * html .goog-custom-button-disabled {
      margin: 2px 1px !important;
      padding: 0 1px !important;
    }

    
    *:first-child+html .goog-custom-button-disabled {
      margin: 2px 1px !important;
      padding: 0 1px !important;
    }

    .goog-custom-button-hover .goog-custom-button-outer-box,
    .goog-custom-button-hover .goog-custom-button-inner-box {
      border-color: #9cf #69e #69e #7af !important; 
    }

    .goog-custom-button-active,
    .goog-custom-button-checked {
      background-color: #bbb;
      background-position: bottom left;
    }

    .goog-custom-button-focused .goog-custom-button-outer-box,
    .goog-custom-button-focused .goog-custom-button-inner-box {
      border-color: orange;
    }

    
    .goog-custom-button-collapse-right,
    .goog-custom-button-collapse-right .goog-custom-button-outer-box,
    .goog-custom-button-collapse-right .goog-custom-button-inner-box {
      margin-right: 0;
    }

    .goog-custom-button-collapse-left,
    .goog-custom-button-collapse-left .goog-custom-button-outer-box,
    .goog-custom-button-collapse-left .goog-custom-button-inner-box {
      margin-left: 0;
    }

    .goog-custom-button-collapse-left .goog-custom-button-inner-box  {
      border-left: 1px solid #fff;
    }

    .goog-custom-button-collapse-left.goog-custom-button-checked
    .goog-custom-button-inner-box {
      border-left: 1px solid #ddd;
    }

    
    * html .goog-custom-button-collapse-left .goog-custom-button-inner-box {
      left: 0;
    }

    
    *:first-child+html .goog-custom-button-collapse-left
    .goog-custom-button-inner-box {
      left: 0;
    }
  </style>
<style type="text/css">
    #controlbar {
      background-image: none;
      border-bottom: 1px solid #e5e5e5;
      min-height: 35px;
      width: 100%;
      padding-bottom: 0;
      padding-top: 0;
    }

    
    #controlbarControls {
      
        float: right;
      
    }

    
    .toolbar-button-icon {
      background-image:
        url("//www.gstatic.com/docs/gview/images/icon_sprites_6.png");
      background-repeat: no-repeat;
      font-size: 0;
      height: 21px;
      line-height: 0;
      vertical-align: middle;
      width: 21px;
    }

    
    #controlbar .docs-icon {
      margin-top: 0;
    }

    
      #prevToolbarButtonIcon {
        background-position: 0;
      }

      #nextToolbarButtonIcon {
        background-position: -21px;
      }
    

    #printToolbarButtonIcon {
      background-position: -146px;
    }

    #zoomOutToolbarButtonIcon {
      background-position: -63px;
    }

    #zoomInToolbarButtonIcon {
      background-position: -42px;
    }

    #openInViewerButtonIcon {
      background-position: -190px;
    }

    #searchIcon {
      background-position: -126px;
      margin: 0;
      
        left: 4px;
      
      position: absolute;
      top: 7px;
      z-index: 999;
    }

    
    #searchElements .goog-control-disabled {
      opacity: 0.3;
    }

    #prevSearchToolbarButton {
      background-position: -85px;
      
        left: 236px;
      
      position: absolute;
      top: 7px;
    }

    #nextSearchToolbarButton {
      background-position: -105px;
      
        left: 256px;
      
      position: absolute;
      top: 7px;
    }

    .label-input-label {
      color: #999;
    }

    .search-box {
      border: 1px #ebebeb solid;
      height: 20px;
      
        margin: 5px 0 0 3px;
        padding-left: 20px;
        padding-right: 47px;
      
      position: relative;
      vertical-align: middle;
      width: 210px;
    }

    
    * html .search-box, *:first-child+html .search-box {
      height: 22px;
      width: 277px;
    }

    .search-box:focus {
      border-color: #0094ff;
      outline-width: 0;
    }

    .search-message {
      color: #000;
      font-size: 12px;
      margin: 11px 4px 0;
    }

    .search-nomatches {
      color: #f00;
    }

    #buttonElements {
      
      
        float: left;
        margin-left: 39px;
      
    }

    #searchElements {
      
        float: right;
        margin-right: 44px;
      
    }

    .separator {
      font-size: 0;
      line-height: 0;
      width: 12px;
    }
  </style>

<style type="text/css">
    .thumb-pane {
      background-color: #ebebeb;
      border: 0;
      color: #666;
      position: fixed;
      z-index: 1;
    }

    
    * html .thumb-pane {
      position: absolute !important;
    }

    
    .thumb-pane-upper-item {
      
      font-size: 0;
    }

    .thumb-pane-lower {
      overflow: auto;
    }

    .goog-useragent-ie .thumb-pane-lower {
      
      position: relative;
    }

    
    .thumb-elements {
      
      padding-top: 13px;
    }

    .thumb-element {
      
      color: #666;
      
      
        padding: 9px 0 0 41px;
      
    }

    .thumb-image-emphasized .page-number {
      color: #0093ff;
    }

    .thumb-highlight {
      cursor: pointer !important;
      opacity: 0.50;
      -moz-opacity: 0.50;
      -khtml-opacity: 0.50;
      filter: alpha(opacity=50);
      background-color: #FF6;
      padding: 3px;
      
      margin-left: -41px;
    }

    
    * html .thumb-highlight, *:first-child+html .thumb-highlight {
      margin-left: 0;
    }

    .thumb-image {
      border: 1px #dadada solid;
      margin: 2px;
      cursor: pointer;
    }

    img.thumb-image-emphasized {
      border: 3px #0093ff solid;
      -webkit-border-radius: 3px;
      -moz-border-radius: 3px;
      border-radius: 3px;
      cursor: pointer;
    }

    .page-number {
      font-weight: bold;
      
        padding-left: 12px;
        padding-right: 6px;
      
      position: relative;
      top: -2px;
    }

    
    #thumb-pane-toggle {
      background-color: #ebebeb;
      position: absolute;
      top: -4px;
      background-image:
        url("//www.gstatic.com/docs/gview/images/icon_sprites_6.png");
      height: 21px;
      width: 21px;
      z-index: 100;
    }

    .goog-useragent-webkit #thumb-pane-toggle {
      
        right: -22px;
      
    }

    .goog-useragent-gecko #thumb-pane-toggle {
      
        right: -22px;
      
    }

    .goog-useragent-ie #thumb-pane-toggle {
      
        right: 16px; 
      
    }

    
      .thumb-pane-show {
        background-position: 0px;
      }

      .thumb-pane-hide {
        background-position: -21px;
        opacity: 0.55;
      }
    
  </style>
<style type="text/css">.view { background-color: #ebebeb; width: 100%; } #content-pane { background-color: #ebebeb; border: 0; height: 100%; outline: none; overflow: auto; position: fixed; text-align: center; width: 100%; } * html #content-pane { position: absolute !important; } #page-pane { color: #666; } .page-element { padding: 24px 0;  } .highlight { position: absolute; font-size: 0; line-height: 0; cursor: text; border-style: none; } .selection-highlight { opacity: 0.20; -moz-opacity: 0.20; -khtml-opacity: 0.20; filter: alpha(opacity=20); background-color: #28F; } .search-highlight { opacity: 0.50; -moz-opacity: 0.50; -khtml-opacity: 0.50; filter: alpha(opacity=50); background-color: #FF6; } .selected-highlight { background-color: #FF9632 !important; } .corner-tl, .corner-br { width: 0; border-style: solid solid none !important; } .corner-tr, .corner-bl { width: 0; border-style: solid none none solid !important; } .corner-bg { z-index: 4; } .corner-tl-fg, .corner-tr-fg { border-color: #ebebeb transparent; z-index: 5; } .corner-br-fg, .corner-bl-fg { border-color: transparent #ebebeb; z-index: 5; } .transparent-highlight { display: none; } .document-link { position: absolute; font-size: 0; z-index: 10; } .goog-useragent-ie .document-link { background-color: #000; opacity: 0.00; -moz-opacity: 0.00; -khtml-opacity: 0.00; filter: alpha(opacity=0); } .highlight-pane { position: relative; } .goog-useragent-ie .highlight-pane { position: absolute; zoom: 1; } .rubberband { border: 1px dashed green; width: 0; height: 0; position: absolute; z-index: 5; } #selection-content { position: absolute; left: 0; top: -48px; width: 32px; height: 32px; } table.gaialinks span { white-space: nowrap; } .noselect .page-image, .noselect .highlight { cursor: auto; } .page-image { border: 1px #dadada solid; cursor: text; margin: 0 8px; } .error-message-strong { font-size: 14px; font-weight: bold; } .error-message { line-height: 2em; text-align: center; color: #000; margin: 50px 42px 0; } .goog-inline-follow { vertical-align: top; } .goog-inline-follow-pad { vertical-align: top; margin-left: 12px; } #loading { text-align: left; margin: 50px auto 100px; width: 30%; } .goog-custom-button-disabled .goog-menu-button-dropdown, .goog-custom-button-disabled .apps-share-sprite { opacity: 0.40; -moz-opacity: 0.40; -khtml-opacity: 0.40; filter: alpha(opacity=40); } .progress-bar-horizontal { border: 1px #999 solid; padding: 1px; width: 100%; } .progress-bar-thumb { background-color: #ccc; height: 8px; width: 20%; }  #password-div { background: white; border: 1px solid black; width: 350px; padding: 1em; margin: 20px auto; } .docs-title-strut { margin-bottom: -20px; } .accessibility-text { font-size: 1px; height: 1px !important; left: -999em !important; overflow: hidden !important; position: fixed !important; top: 50% !important; width: 1px !important; } * html .accessibility-text { position: absolute !important; }</style>
<style type="text/css">
    div.CSS_SHORTCUTS_HELP_POPUP {
      left: 10%;
      width: 80%;
      top: 10%;

      z-index: 1002;
      color: #dd0;

      position: absolute;
      text-align: center;
      text-shadow: #000 1px 1px 7px;
      font-weight: bold;

      background: #000 none repeat scroll 0;
      overflow: hidden;
      padding: 1em;
    }

    @media print {
      div.CSS_SHORTCUTS_HELP_POPUP {
        display: none !important;
      }
    }

    table.CSS_SHORTCUTS_HELP_POPUP_HEADER,
      table.CSS_SHORTCUTS_HELP_POPUP_CONTENT {
      width: 100%;
    }

    .CSS_SHORTCUTS_HELP_POPUP_HEADER_TABLE_ELEMENT {
      padding-bottom: 0.8ex;
    }

    .CSS_SHORTCUTS_HELP_POPUP_TITLE {
      color: #fff;
      font-size: 15px;
      white-space: nowrap;
      text-align: left;
      font-weight: bold;
    }

    .CSS_SHORTCUTS_HELP_POPUP_TEAROFF_LINK_CONTAINER {
      color: #dd0;
      text-align: right;
    }

    .CSS_SHORTCUTS_HELP_POPUP_TEAROFF_LINK {
      font-size: 15px;
      cursor: pointer;
      text-decoration: underline;
      color: #dd0;
    }

    table.CSS_SHORTCUTS_HELP_POPUP_CONTENT {
      color: #dd0;
      border-top: 1px solid #999;
      font-size: 13px;
    }

    .CSS_SHORTCUTS_HELP_POPUP_CONTENT_HEADER {
      color: #dd0;
      padding-top: 1em;
      text-align: left;
      font-size: 13px;
    }

    .CSS_SHORTCUTS_HELP_POPUP_CONTENT_ELEMENT {
      vertical-align: top;
      padding-top: 0.15em;
    }

    table.CSS_SHORTCUTS_HELP_POPUP_CONTENT td.CSS_SHORTCUTS_HELP_POPUP_KEY {
      font-weight: bold;
      padding-right: 0.3em;
      text-align: right;
      white-space: nowrap;
      color: #dd0;
      font-size: 13px;
    }

    table.CSS_SHORTCUTS_HELP_POPUP_CONTENT
      td.CSS_SHORTCUTS_HELP_POPUP_DESCRIPTION {
      font-weight: normal;
      text-align: left;
      color: #fff;
      font-size: 13px;
    }

    span.CSS_SHORTCUTS_HELP_POPUP_AUXILIARY_WORD {
      font-weight: normal;
      font-size: 11px;
      color: #fff;
    }

    span.CSS_SHORTCUTS_HELP_POPUP_KEY_MNEMONIC {
      font-family: "Courier New";
      color: #dd0;
    }
  </style>
<style type="text/css">
    html {
      margin: 0;
      padding: 0;
      height: 100%;
    }

    body {
      margin: 0;
      padding: 0;
      font-family: arial, sans-serif;
      font-size: 13px;
      color: #000;
      height: 100%;
      
      
        
        overflow: hidden;
      
    }

    
    #gview {
      position: static;
    }

    #docs-editor {
      overflow: hidden;
    }

    
    #docs-opt-bar {
      display: block !important;
    }
  </style>
<style type="text/css">
/* Copyright 2014 Google Inc. All Rights Reserved. */
.goog-inline-block{position:relative;display:-moz-inline-box;display:inline-block}* html .goog-inline-block{display:inline}*:first-child+html .goog-inline-block{display:inline}.docs-feedback{-webkit-box-shadow:0 0 6px #808080;-moz-box-shadow:0 0 6px #808080;box-shadow:0 0 6px #808080;bottom:-1px;position:fixed;right:-1px;z-index:2000}.docs-feedback:active{-webkit-box-shadow:0 2px 6px #808080;-moz-box-shadow:0 2px 6px #808080;box-shadow:0 2px 6px #808080}.apps-share-sprite{background-image:url(//ssl.gstatic.com/docs/documents/share/images/sprite-13.svg)}.apps-share-icon{direction:ltr;text-align:left;position:relative;width:21px;height:21px;overflow:hidden}.apps-share-icon-img:before{content:url(//ssl.gstatic.com/docs/documents/share/images/sprite-13.svg)}.apps-share-icon-img{background:url(//ssl.gstatic.com/docs/documents/share/images/sprite-13.svg) no-repeat}.apps-share-icon-img-container{height:352px;position:absolute;width:42px}.jfk-butterBar{-webkit-border-radius:2px;-moz-border-radius:2px;border-radius:2px;-webkit-box-shadow:0px 2px 4px rgba(0,0,0,0.2);-moz-box-shadow:0px 2px 4px rgba(0,0,0,0.2);box-shadow:0px 2px 4px rgba(0,0,0,0.2);-webkit-transition:all 0 linear 1s,opacity 1s;-moz-transition:all 0 linear 1s,opacity 1s;-o-transition:all 0 linear 1s,opacity 1s;transition:all 0 linear 1s,opacity 1s;border-style:solid;border-width:0;font-size:11px;height:0;opacity:0;visibility:hidden;overflow:hidden;padding:0;text-align:center}.jfk-butterBar-info{background-color:#f9edbe;border-color:#f0c36d;color:#333}.jfk-butterBar-error{background-color:#484848;border-color:#202020;color:#fff}.jfk-butterBar-promo{background-color:#d6e9f8;border-color:#4d90f0;color:#333}.jfk-butterBar-warning{background-color:#dd4b39;border-color:#602019;color:#fff}.jfk-butterBar-shown{-webkit-transition:opacity 0.218s;-moz-transition:opacity 0.218s;-o-transition:opacity 0.218s;transition:opacity 0.218s;border-width:1px;height:14px;opacity:1;visibility:visible;padding:6px 16px}.jfk-butterBar-mini.jfk-butterBar-shown{padding:2px 16px}.jfk-button{-webkit-border-radius:2px;-moz-border-radius:2px;border-radius:2px;cursor:default;font-size:11px;font-weight:bold;text-align:center;white-space:nowrap;margin-right:16px;height:27px;line-height:27px;min-width:54px;outline:0px;padding:0 8px}.jfk-button-hover{-webkit-box-shadow:0 1px 1px rgba(0,0,0,.1);-moz-box-shadow:0 1px 1px rgba(0,0,0,.1);box-shadow:0 1px 1px rgba(0,0,0,.1)}.jfk-button-selected{-webkit-box-shadow:inset 0px 1px 2px rgba(0,0,0,0.1);-moz-box-shadow:inset 0px 1px 2px rgba(0,0,0,0.1);box-shadow:inset 0px 1px 2px rgba(0,0,0,0.1)}.jfk-button .jfk-button-img{margin-top:-3px;vertical-align:middle}.jfk-button-label{margin-left:5px}.jfk-button-narrow{min-width:34px;padding:0}.jfk-button-collapse-left,.jfk-button-collapse-right{z-index:1}.jfk-button-collapse-left.jfk-button-disabled{z-index:0}.jfk-button-checked.jfk-button-collapse-left,.jfk-button-checked.jfk-button-collapse-right{z-index:2}.jfk-button-collapse-left:focus,.jfk-button-collapse-right:focus,.jfk-button-hover.jfk-button-collapse-left,.jfk-button-hover.jfk-button-collapse-right{z-index:3}.jfk-button-collapse-left{margin-left:-1px;-moz-border-radius-bottomleft:0;-moz-border-radius-topleft:0;-webkit-border-bottom-left-radius:0;-webkit-border-top-left-radius:0;border-bottom-left-radius:0;border-top-left-radius:0}.jfk-button-collapse-right{margin-right:0px;-moz-border-radius-topright:0;-moz-border-radius-bottomright:0;-webkit-border-top-right-radius:0;-webkit-border-bottom-right-radius:0;border-top-right-radius:0;border-bottom-right-radius:0}.jfk-button.jfk-button-disabled:active{-webkit-box-shadow:none;-moz-box-shadow:none;box-shadow:none}.jfk-button-action{-webkit-box-shadow:none;-moz-box-shadow:none;box-shadow:none;background-color:#4d90fe;background-image:-webkit-linear-gradient(top,#4d90fe,#4787ed);background-image:-moz-linear-gradient(top,#4d90fe,#4787ed);background-image:-ms-linear-gradient(top,#4d90fe,#4787ed);background-image:-o-linear-gradient(top,#4d90fe,#4787ed);background-image:linear-gradient(top,#4d90fe,#4787ed);border:1px solid #3079ed;color:#fff}.jfk-button-action.jfk-button-hover{-webkit-box-shadow:none;-moz-box-shadow:none;box-shadow:none;background-color:#357ae8;background-image:-webkit-linear-gradient(top,#4d90fe,#357ae8);background-image:-moz-linear-gradient(top,#4d90fe,#357ae8);background-image:-ms-linear-gradient(top,#4d90fe,#357ae8);background-image:-o-linear-gradient(top,#4d90fe,#357ae8);background-image:linear-gradient(top,#4d90fe,#357ae8);border:1px solid #2f5bb7;border-bottom-color:#2f5bb7}.jfk-button-action:focus{-webkit-box-shadow:inset 0 0 0 1px #fff;-moz-box-shadow:inset 0 0 0 1px #fff;box-shadow:inset 0 0 0 1px #fff;border:1px solid #fff;border:rgba(0,0,0,0) solid 1px;outline:1px solid #4d90fe;outline:rgba(0,0,0,0) 0}.jfk-button-action.jfk-button-clear-outline{-webkit-box-shadow:none;-moz-box-shadow:none;box-shadow:none;outline:none}.jfk-button-action:active{-webkit-box-shadow:inset 0 1px 2px rgba(0,0,0,0.3);-moz-box-shadow:inset 0 1px 2px rgba(0,0,0,0.3);box-shadow:inset 0 1px 2px rgba(0,0,0,0.3);background:#357ae8;border:1px solid #2f5bb7;border-top:1px solid #2f5bb7}.jfk-button-action.jfk-button-disabled{background:#4d90fe;filter:alpha(opacity=50);opacity:0.5}.jfk-button-contrast{-webkit-box-shadow:none;-moz-box-shadow:none;box-shadow:none;background-color:#f5f5f5;background-image:-webkit-linear-gradient(top,#f5f5f5,#f1f1f1);background-image:-moz-linear-gradient(top,#f5f5f5,#f1f1f1);background-image:-ms-linear-gradient(top,#f5f5f5,#f1f1f1);background-image:-o-linear-gradient(top,#f5f5f5,#f1f1f1);background-image:linear-gradient(top,#f5f5f5,#f1f1f1);color:#333;border:1px solid #dcdcdc;border:1px solid rgba(0,0,0,0.1)}.jfk-button-contrast.jfk-button-hover,.jfk-button-contrast.jfk-button-clear-outline.jfk-button-hover{-webkit-box-shadow:none;-moz-box-shadow:none;box-shadow:none;background-color:#f8f8f8;background-image:-webkit-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:-moz-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:-ms-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:-o-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:linear-gradient(top,#f8f8f8,#f1f1f1);border:1px solid #c6c6c6;color:#111}.jfk-button-contrast:active,.jfk-button-contrast.jfk-button-hover:active{-webkit-box-shadow:inset 0 1px 2px rgba(0,0,0,.1);-moz-box-shadow:inset 0 1px 2px rgba(0,0,0,.1);box-shadow:inset 0 1px 2px rgba(0,0,0,.1);background:#f8f8f8}.jfk-button-contrast.jfk-button-selected,.jfk-button-contrast.jfk-button-clear-outline.jfk-button-selected{background-color:#eee;background-image:-webkit-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:-moz-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:-ms-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:-o-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:linear-gradient(top,#f8f8f8,#f1f1f1);border:1px solid #ccc;color:#333}.jfk-button-contrast.jfk-button-checked,.jfk-button-contrast.jfk-button-clear-outline.jfk-button-checked{-webkit-box-shadow:inset 0 1px 2px rgba(0,0,0,.1);-moz-box-shadow:inset 0 1px 2px rgba(0,0,0,.1);box-shadow:inset 0 1px 2px rgba(0,0,0,.1);background-color:#eee;background-image:-webkit-linear-gradient(top,#eee,#e0e0e0);background-image:-moz-linear-gradient(top,#eee,#e0e0e0);background-image:-ms-linear-gradient(top,#eee,#e0e0e0);background-image:-o-linear-gradient(top,#eee,#e0e0e0);background-image:linear-gradient(top,#eee,#e0e0e0);border:1px solid #ccc;color:#333}.jfk-button-contrast:focus{border:1px solid #4d90fe;outline:none}.jfk-button-contrast.jfk-button-clear-outline{border:1px solid #dcdcdc;outline:none}.jfk-button-contrast.jfk-button-disabled{background:#fff;border:1px solid #f3f3f3;border:1px solid rgba(0,0,0,0.05);color:#b8b8b8}.jfk-button-contrast .jfk-button-img{opacity:.70}.jfk-button-contrast.jfk-button-checked .jfk-button-img,.jfk-button-contrast.jfk-button-selected .jfk-button-img,.jfk-button-contrast.jfk-button-hover .jfk-button-img{opacity:0.9}.jfk-button-contrast.jfk-button-disabled .jfk-button-img{filter:alpha(opacity=33);opacity:0.333}.jfk-button-default{-webkit-box-shadow:none;-moz-box-shadow:none;box-shadow:none;background-color:#3d9400;background-image:-webkit-linear-gradient(top,#3d9400,#398a00);background-image:-moz-linear-gradient(top,#3d9400,#398a00);background-image:-ms-linear-gradient(top,#3d9400,#398a00);background-image:-o-linear-gradient(top,#3d9400,#398a00);background-image:linear-gradient(top,#3d9400,#398a00);border:1px solid #29691d;color:#fff;text-shadow:0px 1px rgba(0,0,0,0.1)}.jfk-button-default.jfk-button-hover{-webkit-box-shadow:none;-moz-box-shadow:none;box-shadow:none;background-color:#368200;background-image:-webkit-linear-gradient(top,#3d9400,#368200);background-image:-moz-linear-gradient(top,#3d9400,#368200);background-image:-ms-linear-gradient(top,#3d9400,#368200);background-image:-o-linear-gradient(top,#3d9400,#368200);background-image:linear-gradient(top,#3d9400,#368200);border:1px solid #2d6200;border-bottom:1px solid #2d6200;text-shadow:0px 1px rgba(0,0,0,0.3)}.jfk-button-default:focus{-webkit-box-shadow:inset 0 0 0 1px #fff;-moz-box-shadow:inset 0 0 0 1px #fff;box-shadow:inset 0 0 0 1px #fff;border:1px solid #fff;border:rgba(0,0,0,0) solid 1px;outline:1px solid #3d9400;outline:rgba(0,0,0,0) 0}.jfk-button-default.jfk-button-clear-outline{-webkit-box-shadow:none;-moz-box-shadow:none;box-shadow:none;outline:none}.jfk-button-default:active{-webkit-box-shadow:inset 0px 1px 2px rgba(0,0,0,0.3);-moz-box-shadow:inset 0px 1px 2px rgba(0,0,0,0.3);box-shadow:inset 0px 1px 2px rgba(0,0,0,0.3);background:#368200;border:1px solid #2d6200;border-top:1px solid #2d6200}.jfk-button-default.jfk-button-disabled{background:#3d9400;filter:alpha(opacity=50);opacity:0.5}.jfk-button-primary{-webkit-box-shadow:none;-moz-box-shadow:none;box-shadow:none;background-color:#d14836;background-image:-webkit-linear-gradient(top,#dd4b39,#d14836);background-image:-moz-linear-gradient(top,#dd4b39,#d14836);background-image:-ms-linear-gradient(top,#dd4b39,#d14836);background-image:-o-linear-gradient(top,#dd4b39,#d14836);background-image:linear-gradient(top,#dd4b39,#d14836);border:1px solid transparent;color:#fff;text-shadow:0px 1px rgba(0,0,0,0.1);text-transform:uppercase}.jfk-button-primary.jfk-button-hover{-webkit-box-shadow:0px 1px 1px rgba(0,0,0,0.2);-moz-box-shadow:0px 1px 1px rgba(0,0,0,0.2);box-shadow:0px 1px 1px rgba(0,0,0,0.2);background-color:#c53727;background-image:-webkit-linear-gradient(top,#dd4b39,#c53727);background-image:-moz-linear-gradient(top,#dd4b39,#c53727);background-image:-ms-linear-gradient(top,#dd4b39,#c53727);background-image:-o-linear-gradient(top,#dd4b39,#c53727);background-image:linear-gradient(top,#dd4b39,#c53727);border:1px solid #b0281a;border-bottom-color:#af301f}.jfk-button-primary:focus{-webkit-box-shadow:inset 0 0 0 1px #fff;-moz-box-shadow:inset 0 0 0 1px #fff;box-shadow:inset 0 0 0 1px #fff;border:1px solid #fff;border:rgba(0,0,0,0) solid 1px;outline:1px solid #d14836;outline:rgba(0,0,0,0) 0}.jfk-button-primary.jfk-button-clear-outline{-webkit-box-shadow:none;-moz-box-shadow:none;box-shadow:none;outline:none}.jfk-button-primary:active{-webkit-box-shadow:inset 0px 1px 2px rgba(0,0,0,0.3);-moz-box-shadow:inset 0px 1px 2px rgba(0,0,0,0.3);box-shadow:inset 0px 1px 2px rgba(0,0,0,0.3);background-color:#b0281a;background-image:-webkit-linear-gradient(top,#dd4b39,#b0281a);background-image:-moz-linear-gradient(top,#dd4b39,#b0281a);background-image:-ms-linear-gradient(top,#dd4b39,#b0281a);background-image:-o-linear-gradient(top,#dd4b39,#b0281a);background-image:linear-gradient(top,#dd4b39,#b0281a);border:1px solid #992a1b;border-top:1px solid #992a1b}.jfk-button-primary.jfk-button-disabled{background:#d14836;filter:alpha(opacity=50);opacity:0.5}.jfk-slideToggle{-webkit-border-radius:2px;-moz-border-radius:2px;border-radius:2px;-webkit-box-shadow:inset 0px 1px 2px 0 rgba(0,0,0,.1);-moz-box-shadow:inset 0px 1px 2px 0 rgba(0,0,0,.1);box-shadow:inset 0px 1px 2px 0 rgba(0,0,0,.1);background-color:#f5f5f5;background-image:-webkit-linear-gradient(top,#eee,#e0e0e0);background-image:-moz-linear-gradient(top,#eee,#e0e0e0);background-image:-ms-linear-gradient(top,#eee,#e0e0e0);background-image:-o-linear-gradient(top,#eee,#e0e0e0);background-image:linear-gradient(top,#eee,#e0e0e0);border:1px solid #ccc;color:#666;font-weight:bold;height:27px;line-height:27px;margin-right:16px;outline:none;overflow:hidden;padding:0;position:relative;width:94px}.jfk-slideToggle-on,.jfk-slideToggle-off,.jfk-slideToggle-thumb{display:inline-block;text-align:center;text-transform:uppercase;width:47px}.jfk-slideToggle-on{-webkit-box-shadow:inset 0 1px 2px 0 rgba(0,0,0,.1);-moz-box-shadow:inset 0 1px 2px 0 rgba(0,0,0,.1);box-shadow:inset 0 1px 2px 0 rgba(0,0,0,.1);background-color:#398bf2;background-image:-webkit-linear-gradient(top,#3b93ff,#3689ee);background-image:-moz-linear-gradient(top,#3b93ff,#3689ee);background-image:-ms-linear-gradient(top,#3b93ff,#3689ee);background-image:-o-linear-gradient(top,#3b93ff,#3689ee);background-image:linear-gradient(top,#3b93ff,#3689ee);color:#fff;height:27px}.jfk-slideToggle-off{-webkit-border-radius:2px 2px 0 0;-moz-border-radius:2px 2px 0 0;border-radius:2px 2px 0 0}.jfk-slideToggle-thumb{-webkit-box-shadow:0px 1px 2px 0 rgba(0,0,0,.1);-moz-box-shadow:0px 1px 2px 0 rgba(0,0,0,.1);box-shadow:0px 1px 2px 0 rgba(0,0,0,.1);background-color:#f5f5f5;background-image:-webkit-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:-moz-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:-ms-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:-o-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:linear-gradient(top,#f8f8f8,#f1f1f1);-webkit-transition:all .130s ease-out;-moz-transition:all .130s ease-out;-o-transition:all .130s ease-out;transition:all .130s ease-out;border:1px solid #ccc;display:block;height:27px;left:-1px;position:absolute;top:-1px}.jfk-slideToggle-thumb::after{content:'';background-image:-webkit-linear-gradient(left,#ccc 50%,transparent 50%),-webkit-linear-gradient(left,#ccc 50%,transparent 50%),-webkit-linear-gradient(left,#ccc 50%,transparent 50%),-webkit-linear-gradient(left,#ccc 50%,transparent 50%),-webkit-linear-gradient(left,#ccc 50%,transparent 50%);background-image:-moz-linear-gradient(left,#ccc 50%,transparent 50%),-moz-linear-gradient(left,#ccc 50%,transparent 50%),-moz-linear-gradient(left,#ccc 50%,transparent 50%),-moz-linear-gradient(left,#ccc 50%,transparent 50%),-moz-linear-gradient(left,#ccc 50%,transparent 50%);background-image:-ms-linear-gradient(left,#ccc 50%,transparent 50%),-ms-linear-gradient(left,#ccc 50%,transparent 50%),-ms-linear-gradient(left,#ccc 50%,transparent 50%),-ms-linear-gradient(left,#ccc 50%,transparent 50%),-ms-linear-gradient(left,#ccc 50%,transparent 50%);background-image:-o-linear-gradient(left,#ccc 50%,transparent 50%),-o-linear-gradient(left,#ccc 50%,transparent 50%),-o-linear-gradient(left,#ccc 50%,transparent 50%),-o-linear-gradient(left,#ccc 50%,transparent 50%),-o-linear-gradient(left,#ccc 50%,transparent 50%);background-image:linear-gradient(left,#ccc 50%,transparent 50%),linear-gradient(left,#ccc 50%,transparent 50%),linear-gradient(left,#ccc 50%,transparent 50%),linear-gradient(left,#ccc 50%,transparent 50%),linear-gradient(left,#ccc 50%,transparent 50%);background-position:0 0,0 2px,0 4px,0 6px,0 8px;background-repeat:repeat-x;background-size:2px 1px;display:block;height:9px;left:15px;position:absolute;top:9px;width:17px}.jfk-slideToggle.jfk-slideToggle-checked .jfk-slideToggle-thumb{left:47px}.jfk-slideToggle:focus{border:1px solid #4d90fe}.jfk-slideToggle.jfk-slideToggle-clearOutline{border:1px solid #ccc}.jfk-button-standard{-webkit-box-shadow:none;-moz-box-shadow:none;box-shadow:none;background-color:#f5f5f5;background-image:-webkit-linear-gradient(top,#f5f5f5,#f1f1f1);background-image:-moz-linear-gradient(top,#f5f5f5,#f1f1f1);background-image:-ms-linear-gradient(top,#f5f5f5,#f1f1f1);background-image:-o-linear-gradient(top,#f5f5f5,#f1f1f1);background-image:linear-gradient(top,#f5f5f5,#f1f1f1);color:#333;border:1px solid #dcdcdc;border:1px solid rgba(0,0,0,0.1)}.jfk-button-standard.jfk-button-hover,.jfk-button-standard.jfk-button-clear-outline.jfk-button-hover{-webkit-box-shadow:none;-moz-box-shadow:none;box-shadow:none;background-color:#f8f8f8;background-image:-webkit-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:-moz-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:-ms-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:-o-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:linear-gradient(top,#f8f8f8,#f1f1f1);border:1px solid #c6c6c6;color:#111}.jfk-button-standard:active,.jfk-button-standard.jfk-button-hover:active{-webkit-box-shadow:inset 0 1px 2px rgba(0,0,0,.1);-moz-box-shadow:inset 0 1px 2px rgba(0,0,0,.1);box-shadow:inset 0 1px 2px rgba(0,0,0,.1);background:#f8f8f8;color:#111}.jfk-button-standard.jfk-button-selected,.jfk-button-standard.jfk-button-clear-outline.jfk-button-selected{background-color:#eee;background-image:-webkit-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:-moz-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:-ms-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:-o-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:linear-gradient(top,#f8f8f8,#f1f1f1);border:1px solid #ccc;color:#333}.jfk-button-standard.jfk-button-checked,.jfk-button-standard.jfk-button-clear-outline.jfk-button-checked{-webkit-box-shadow:inset 0 1px 2px rgba(0,0,0,.1);-moz-box-shadow:inset 0 1px 2px rgba(0,0,0,.1);box-shadow:inset 0 1px 2px rgba(0,0,0,.1);background-color:#eee;background-image:-webkit-linear-gradient(top,#eee,#e0e0e0);background-image:-moz-linear-gradient(top,#eee,#e0e0e0);background-image:-ms-linear-gradient(top,#eee,#e0e0e0);background-image:-o-linear-gradient(top,#eee,#e0e0e0);background-image:linear-gradient(top,#eee,#e0e0e0);border:1px solid #ccc;color:#333}.jfk-button-standard:focus{border:1px solid #4d90fe;outline:none}.jfk-button-standard.jfk-button-clear-outline{border:1px solid #dcdcdc;border:1px solid rgba(0,0,0,0.1);outline:none}.jfk-button-standard.jfk-button-disabled{background:#fff;border:1px solid #f3f3f3;border:1px solid rgba(0,0,0,0.05);color:#b8b8b8}.jfk-button-standard .jfk-button-img{opacity:.70}.jfk-button-standard.jfk-button-checked .jfk-button-img,.jfk-button-standard.jfk-button-selected .jfk-button-img,.jfk-button-standard.jfk-button-hover .jfk-button-img{opacity:0.9}.jfk-button-standard.jfk-button-disabled .jfk-button-img{filter:alpha(opacity=33);opacity:0.333}.jfk-button-flat{-webkit-border-radius:0;-moz-border-radius:0;border-radius:0;border:1px solid transparent;font-size:13px;font-weight:normal;height:21px;line-height:21px;margin-right:1px;min-width:0;padding:0}.jfk-button-flat.jfk-button-hover,.jfk-button-flat.jfk-button-selected,.jfk-button-flat:focus,.jfk-button-flat:active{-webkit-box-shadow:none;-moz-box-shadow:none;box-shadow:none}.jfk-button-flat .jfk-button-img{height:21px;opacity:.70;width:21px}.jfk-button-flat .jfk-button-label{display:inline-block;margin:0;padding:0 1px}.jfk-button-flat.jfk-button-selected .jfk-button-img,.jfk-button-flat.jfk-button-hover .jfk-button-img{opacity:0.9}.jfk-button-flat.jfk-button-disabled .jfk-button-img{filter:alpha(opacity=33);opacity:0.333}.jfk-button-flat:focus{border:1px solid #4d90fe}.jfk-button-flat.jfk-button-clear-outline{border:1px solid transparent}.jfk-button-mini{background-color:#f5f5f5;background-image:-webkit-linear-gradient(top,#f5f5f5,#f1f1f1);background-image:-moz-linear-gradient(top,#f5f5f5,#f1f1f1);background-image:-ms-linear-gradient(top,#f5f5f5,#f1f1f1);background-image:-o-linear-gradient(top,#f5f5f5,#f1f1f1);background-image:linear-gradient(top,#f5f5f5,#f1f1f1);border:1px solid #dcdcdc;border:1px solid rgba(0,0,0,0.1);color:#333;height:17px;line-height:17px;min-width:22px;text-shadow:0px 1px rgba(0,0,0,0.1)}.jfk-button-mini.jfk-button-hover,.jfk-button-mini.jfk-button-clear-outline.jfk-button-hover{background-color:#f8f8f8;background-image:-webkit-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:-moz-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:-ms-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:-o-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:linear-gradient(top,#f8f8f8,#f1f1f1);border:1px solid #c6c6c6;text-shadow:0px 1px rgba(0,0,0,0.3)}.jfk-button-mini:active{-webkit-box-shadow:inset 0 1px 2px rgba(0,0,0,.1);-moz-box-shadow:inset 0 1px 2px rgba(0,0,0,.1);box-shadow:inset 0 1px 2px rgba(0,0,0,.1)}.jfk-button-mini.jfk-button-checked,.jfk-button-mini.jfk-button-clear-outline.jfk-button-checked{-webkit-box-shadow:inset 0 1px 2px rgba(0,0,0,.1);-moz-box-shadow:inset 0 1px 2px rgba(0,0,0,.1);box-shadow:inset 0 1px 2px rgba(0,0,0,.1);background-color:#e0e0e0;background-image:-webkit-linear-gradient(top,#eee,#e0e0e0);background-image:-moz-linear-gradient(top,#eee,#e0e0e0);background-image:-ms-linear-gradient(top,#eee,#e0e0e0);background-image:-o-linear-gradient(top,#eee,#e0e0e0);background-image:linear-gradient(top,#eee,#e0e0e0);border:1px solid #ccc;color:#333}.jfk-button-mini:focus{border:1px solid #4d90fe}.jfk-button-mini.jfk-button-clear-outline{border:1px solid #dcdcdc}.jfk-button-mini.jfk-button-disabled{background:#fff;border:1px solid #f3f3f3;border:1px solid rgba(0,0,0,0.05);color:#b8b8b8}.goog-modalpopup,.modal-dialog{-webkit-box-shadow:0 4px 16px rgba(0,0,0,.2);-moz-box-shadow:0 4px 16px rgba(0,0,0,.2);box-shadow:0 4px 16px rgba(0,0,0,.2);background:#fff;background-clip:padding-box;border:1px solid #acacac;border:1px solid rgba(0,0,0,.333);outline:0;position:absolute}.goog-modalpopup-bg,.modal-dialog-bg{background:#fff;left:0;position:absolute;top:0}div.goog-modalpopup-bg,div.modal-dialog-bg{filter:alpha(opacity=75);-moz-opacity:.75;opacity:.75}.modal-dialog{color:#000;padding:30px 42px}.modal-dialog-title{background-color:#fff;color:#000;cursor:default;font-size:16px;font-weight:normal;line-height:24px;margin:0 0 16px}.modal-dialog-title-close{height:11px;opacity:0.7;padding:17px;position:absolute;right:0px;top:0px;width:11px}.modal-dialog-title-close:after{content:'';background:url(//ssl.gstatic.com/ui/v1/dialog/close-x.png);position:absolute;height:11px;width:11px;right:17px}.modal-dialog-title-close:hover{opacity:1}.modal-dialog-content{background-color:#fff;line-height:1.4em}.modal-dialog-buttons{margin-top:16px}.modal-dialog-buttons button{-webkit-border-radius:2px;-moz-border-radius:2px;border-radius:2px;background-color:#f5f5f5;background-image:-webkit-linear-gradient(top,#f5f5f5,#f1f1f1);background-image:-moz-linear-gradient(top,#f5f5f5,#f1f1f1);background-image:-ms-linear-gradient(top,#f5f5f5,#f1f1f1);background-image:-o-linear-gradient(top,#f5f5f5,#f1f1f1);background-image:linear-gradient(top,#f5f5f5,#f1f1f1);border:1px solid #dcdcdc;border:1px solid rgba(0,0,0,0.1);color:#333;cursor:default;font-family:inherit;font-size:11px;font-weight:bold;height:29px;line-height:27px;margin:0 16px 0 0;min-width:72px;outline:0;padding:0 8px}.modal-dialog-buttons button:hover,.modal-dialog-buttons button:active{-webkit-box-shadow:0px 1px 1px rgba(0,0,0,0.1);-moz-box-shadow:0px 1px 1px rgba(0,0,0,0.1);box-shadow:0px 1px 1px rgba(0,0,0,0.1);background-color:#f8f8f8;background-image:-webkit-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:-moz-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:-ms-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:-o-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:linear-gradient(top,#f8f8f8,#f1f1f1);border:1px solid #c6c6c6;color:#111}.modal-dialog-buttons button:active{-webkit-box-shadow:inset 0 1px 2px rgba(0,0,0,.1);-moz-box-shadow:inset 0 1px 2px rgba(0,0,0,.1);box-shadow:inset 0 1px 2px rgba(0,0,0,.1)}.modal-dialog-buttons button:focus{border:1px solid #4d90fe}.modal-dialog-buttons button[disabled]{-webkit-box-shadow:none;-moz-box-shadow:none;box-shadow:none;background:#fff;background-image:none;border:1px solid #f3f3f3;border:1px solid rgba(0,0,0,0.05);color:#b8b8b8}.modal-dialog-buttons .goog-buttonset-action{background-color:#4d90fe;background-image:-webkit-linear-gradient(top,#4d90fe,#4787ed);background-image:-moz-linear-gradient(top,#4d90fe,#4787ed);background-image:-ms-linear-gradient(top,#4d90fe,#4787ed);background-image:-o-linear-gradient(top,#4d90fe,#4787ed);background-image:linear-gradient(top,#4d90fe,#4787ed);border:1px solid #3079ed;color:#fff}.modal-dialog-buttons .goog-buttonset-action:hover,.modal-dialog-buttons .goog-buttonset-action:active{background-color:#357ae8;background-image:-webkit-linear-gradient(top,#4d90fe,#357ae8);background-image:-moz-linear-gradient(top,#4d90fe,#357ae8);background-image:-ms-linear-gradient(top,#4d90fe,#357ae8);background-image:-o-linear-gradient(top,#4d90fe,#357ae8);background-image:linear-gradient(top,#4d90fe,#357ae8);border:1px solid #2f5bb7;color:#fff}.modal-dialog-buttons .goog-buttonset-action:active{-webkit-box-shadow:inset 0 1px 2px rgba(0,0,0,0.3);-moz-box-shadow:inset 0 1px 2px rgba(0,0,0,0.3);box-shadow:inset 0 1px 2px rgba(0,0,0,0.3)}.modal-dialog-buttons .goog-buttonset-action:focus{-webkit-box-shadow:inset 0 0 0 1px #fff;-moz-box-shadow:inset 0 0 0 1px #fff;box-shadow:inset 0 0 0 1px #fff;border:1px solid #fff;border:rgba(0,0,0,0) solid 1px;outline:1px solid #4d90fe;outline:rgba(0,0,0,0) 0}.modal-dialog-buttons .goog-buttonset-action[disabled]{-webkit-box-shadow:none;-moz-box-shadow:none;box-shadow:none;background:#4d90fe;color:#fff;filter:alpha(opacity=50);opacity:0.5}.jfk-alert,.jfk-confirm,.jfk-prompt{width:512px}.goog-menu{-webkit-border-radius:0;-moz-border-radius:0;border-radius:0;-webkit-box-shadow:0 2px 4px rgba(0,0,0,0.2);-moz-box-shadow:0 2px 4px rgba(0,0,0,0.2);box-shadow:0 2px 4px rgba(0,0,0,0.2);-webkit-transition:opacity 0.218s;-moz-transition:opacity 0.218s;-o-transition:opacity 0.218s;transition:opacity 0.218s;background:#fff;border:1px solid #ccc;border:1px solid rgba(0,0,0,.2);cursor:default;font-size:13px;margin:0;outline:none;padding:6px 0;position:absolute}.goog-flat-menu-button{-webkit-border-radius:2px;-moz-border-radius:2px;border-radius:2px;background-color:#f5f5f5;background-image:-webkit-linear-gradient(top,#f5f5f5,#f1f1f1);background-image:-moz-linear-gradient(top,#f5f5f5,#f1f1f1);background-image:-ms-linear-gradient(top,#f5f5f5,#f1f1f1);background-image:-o-linear-gradient(top,#f5f5f5,#f1f1f1);background-image:linear-gradient(top,#f5f5f5,#f1f1f1);border:1px solid #dcdcdc;color:#333;cursor:default;font-size:11px;font-weight:bold;line-height:27px;list-style:none;margin:0 2px;min-width:46px;outline:none;padding:0 18px 0 6px;text-align:center;text-decoration:none}.goog-flat-menu-button-disabled{background-color:#fff;border-color:#f3f3f3;color:#b8b8b8}.goog-flat-menu-button.goog-flat-menu-button-hover{background-color:#f8f8f8;background-image:-webkit-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:-moz-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:-ms-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:-o-linear-gradient(top,#f8f8f8,#f1f1f1);background-image:linear-gradient(top,#f8f8f8,#f1f1f1);-webkit-box-shadow:0 1px 1px rgba(0,0,0,.1);-moz-box-shadow:0 1px 1px rgba(0,0,0,.1);box-shadow:0 1px 1px rgba(0,0,0,.1);border-color:#c6c6c6;color:#111}.goog-flat-menu-button.goog-flat-menu-button-focused{border-color:#4d90fe}.goog-flat-menu-button.goog-flat-menu-button-open,.goog-flat-menu-button.goog-flat-menu-button-active{-webkit-box-shadow:inset 0 1px 2px rgba(0,0,0,.1);-moz-box-shadow:inset 0 1px 2px rgba(0,0,0,.1);box-shadow:inset 0 1px 2px rgba(0,0,0,.1);background-color:#eee;background-image:-webkit-linear-gradient(top,#eee,#e0e0e0);background-image:-moz-linear-gradient(top,#eee,#e0e0e0);background-image:-ms-linear-gradient(top,#eee,#e0e0e0);background-image:-o-linear-gradient(top,#eee,#e0e0e0);background-image:linear-gradient(top,#eee,#e0e0e0);border:1px solid #ccc;color:#333;z-index:2}.goog-flat-menu-button-caption{vertical-align:top;white-space:nowrap}.goog-flat-menu-button-dropdown{border-color:#777 transparent;border-style:solid;border-width:4px 4px 0 4px;height:0;width:0;position:absolute;right:5px;top:12px}.goog-flat-menu-button .goog-flat-menu-button-img{margin-top:-3px;opacity:.70;vertical-align:middle}.goog-flat-menu-button-active .goog-flat-menu-button-img,.goog-flat-menu-button-open .goog-flat-menu-button-img,.goog-flat-menu-button-selected .goog-flat-menu-button-img,.goog-flat-menu-button-hover .goog-flat-menu-button-img{opacity:0.9}.goog-flat-menu-button-active .goog-flat-menu-button-dropdown,.goog-flat-menu-button-open .goog-flat-menu-button-dropdown,.goog-flat-menu-button-selected .goog-flat-menu-button-dropdown,.goog-flat-menu-button-hover .goog-flat-menu-button-dropdown{border-color:#595959 transparent}.goog-flat-menu-button-left,.goog-flat-menu-button-right{z-index:1}.goog-flat-menu-button-left.goog-flat-menu-button-disabled{z-index:0}.goog-flat-menu-button-right:focus,.goog-flat-menu-button-hover.goog-flat-menu-button-collapse-right{z-index:2}.goog-flat-menu-button-left:focus,.goog-flat-menu-button-hover.goog-flat-menu-button-collapse-left{z-index:2}.goog-flat-menu-button-collapse-left{margin-left:-1px;-moz-border-radius-bottomleft:0;-moz-border-radius-topleft:0;-webkit-border-bottom-left-radius:0;-webkit-border-top-left-radius:0;border-bottom-left-radius:0;border-top-left-radius:0;min-width:0;padding-left:0;vertical-align:top}.goog-flat-menu-button-collapse-right{margin-right:0px;-moz-border-radius-topright:0;-moz-border-radius-bottomright:0;-webkit-border-top-right-radius:0;-webkit-border-bottom-right-radius:0;border-top-right-radius:0;border-bottom-right-radius:0}.goog-menuitem,.goog-tristatemenuitem,.goog-filterobsmenuitem{position:relative;color:#333;cursor:pointer;list-style:none;margin:0;padding:6px 8em 6px 30px;white-space:nowrap}.goog-menu-nocheckbox .goog-menuitem,.goog-menu-noicon .goog-menuitem{padding-left:16px;vertical-align:middle}.goog-menu-noaccel .goog-menuitem{padding-right:44px}.goog-menuitem-disabled{cursor:default}.goog-menuitem-disabled .goog-menuitem-accel,.goog-menuitem-disabled .goog-menuitem-content{color:#ccc!important}.goog-menuitem-disabled .goog-menuitem-icon{filter:alpha(opacity=30);opacity:0.3}.goog-menuitem-highlight,.goog-menuitem-hover{background-color:#eee;border-color:#eee;border-style:dotted;border-width:1px 0;padding-top:5px;padding-bottom:5px}.goog-menuitem-highlight .goog-menuitem-content,.goog-menuitem-hover .goog-menuitem-content{color:#333}.goog-menuitem-checkbox,.goog-menuitem-icon{background-repeat:no-repeat;height:21px;left:3px;position:absolute;right:auto;top:3px;vertical-align:middle;width:21px}.goog-option-selected{background-image:url(//ssl.gstatic.com/ui/v1/menu/checkmark.png);background-repeat:no-repeat;background-position:left center}.goog-option-selected .goog-menuitem-content,.goog-option-selected .goog-menuitem-content{color:#333}.goog-menuitem-accel{color:#777;direction:ltr;left:auto;padding:0 6px;position:absolute;right:0;text-align:right}.goog-menuitem-mnemonic-hint{text-decoration:underline}.goog-menuitem-mnemonic-separator{color:#777;font-size:12px;padding-left:4px}.goog-menuseparator{border-top:1px solid #ebebeb;margin-top:6px;margin-bottom:6px}.jfk-bubble{-webkit-box-shadow:0 1px 3px rgba(0,0,0,.2);-moz-box-shadow:0 1px 3px rgba(0,0,0,.2);box-shadow:0 1px 3px rgba(0,0,0,.2);background-color:#fff;border:1px solid;border-color:#bbb #bbb #a8a8a8;padding:16px;position:absolute;z-index:1201!important}.jfk-bubble-closebtn{background:url("//ssl.gstatic.com/ui/v1/icons/common/x_8px.png") no-repeat;border:1px solid transparent;height:21px;opacity:.4;outline:0;position:absolute;right:2px;top:2px;width:21px}.jfk-bubble-closebtn:focus{border:1px solid #4d90fe;opacity:.8}.jfk-bubble-arrow{position:absolute}.jfk-bubble-arrow .jfk-bubble-arrowimplbefore,.jfk-bubble-arrow .jfk-bubble-arrowimplafter{display:block;height:0;position:absolute;width:0}.jfk-bubble-arrow .jfk-bubble-arrowimplbefore{border:9px solid}.jfk-bubble-arrow .jfk-bubble-arrowimplafter{border:8px solid}.jfk-bubble-arrowdown{bottom:0}.jfk-bubble-arrowup{top:-9px}.jfk-bubble-arrowleft{left:-9px}.jfk-bubble-arrowright{right:0}.jfk-bubble-arrowdown .jfk-bubble-arrowimplbefore,.jfk-bubble-arrowup .jfk-bubble-arrowimplbefore{border-color:#bbb transparent;left:-9px}.jfk-bubble-arrowdown .jfk-bubble-arrowimplbefore{border-color:#a8a8a8 transparent}.jfk-bubble-arrowdown .jfk-bubble-arrowimplafter,.jfk-bubble-arrowup .jfk-bubble-arrowimplafter{border-color:#fff transparent;left:-8px}.jfk-bubble-arrowdown .jfk-bubble-arrowimplbefore{border-bottom-width:0}.jfk-bubble-arrowdown .jfk-bubble-arrowimplafter{border-bottom-width:0}.jfk-bubble-arrowup .jfk-bubble-arrowimplbefore{border-top-width:0}.jfk-bubble-arrowup .jfk-bubble-arrowimplafter{border-top-width:0;top:1px}.jfk-bubble-arrowleft .jfk-bubble-arrowimplbefore,.jfk-bubble-arrowright .jfk-bubble-arrowimplbefore{border-color:transparent #bbb;top:-9px}.jfk-bubble-arrowleft .jfk-bubble-arrowimplafter,.jfk-bubble-arrowright .jfk-bubble-arrowimplafter{border-color:transparent #fff;top:-8px}.jfk-bubble-arrowleft .jfk-bubble-arrowimplbefore{border-left-width:0}.jfk-bubble-arrowleft .jfk-bubble-arrowimplafter{border-left-width:0;left:1px}.jfk-bubble-arrowright .jfk-bubble-arrowimplbefore{border-right-width:0}.jfk-bubble-arrowright .jfk-bubble-arrowimplafter{border-right-width:0}.jfk-tooltip{-webkit-border-radius:0;-moz-border-radius:0;border-radius:0;-webkit-box-shadow:none;-moz-box-shadow:none;box-shadow:none;-webkit-transition:visibility 0,opacity .13s ease-in;-moz-transition:visibility 0,opacity .13s ease-in;-o-transition:visibility 0,opacity .13s ease-in;transition:visibility 0,opacity .13s ease-in;background-color:#2a2a2a;border:1px solid #fff;color:#fff;cursor:default;display:block;font-size:11px;font-weight:bold;margin-left:-1px;opacity:1;padding:7px 9px;position:absolute;visibility:visible;word-break:break-all;word-break:break-word}.jfk-tooltip-hide{-webkit-transition:visibility .13s,opacity .13s ease-out,left 0 linear .13s,top 0 linear .13s;-moz-transition:visibility .13s,opacity .13s ease-out,left 0 linear .13s,top 0 linear .13s;-o-transition:visibility .13s,opacity .13s ease-out,left 0 linear .13s,top 0 linear .13s;transition:visibility .13s,opacity .13s ease-out,left 0 linear .13s,top 0 linear .13s;opacity:0;left:20px!important;top:20px!important;visibility:hidden}.jfk-tooltip-data{display:none}.jfk-tooltip-arrow{pointer-events:none;position:absolute}.jfk-tooltip-arrow .jfk-tooltip-arrowimplbefore,.jfk-tooltip-arrow .jfk-tooltip-arrowimplafter{content:'';display:block;height:0;position:absolute;width:0}.jfk-tooltip-arrow .jfk-tooltip-arrowimplbefore{border:6px solid}.jfk-tooltip-arrow .jfk-tooltip-arrowimplafter{border:5px solid}.jfk-tooltip-arrowdown{bottom:0}.jfk-tooltip-arrowup{top:-6px}.jfk-tooltip-arrowleft{left:-6px}.jfk-tooltip-arrowright{right:0}.jfk-tooltip-arrowdown .jfk-tooltip-arrowimplbefore,.jfk-tooltip-arrowup .jfk-tooltip-arrowimplbefore{border-color:#fff transparent;left:-6px}.jfk-tooltip-arrowdown .jfk-tooltip-arrowimplafter,.jfk-tooltip-arrowup .jfk-tooltip-arrowimplafter{border-color:#2a2a2a transparent;left:-5px}.jfk-tooltip-arrowdown .jfk-tooltip-arrowimplbefore{border-bottom-width:0}.jfk-tooltip-arrowdown .jfk-tooltip-arrowimplafter{border-bottom-width:0}.jfk-tooltip-arrowup .jfk-tooltip-arrowimplbefore{border-top-width:0}.jfk-tooltip-arrowup .jfk-tooltip-arrowimplafter{border-top-width:0;top:1px}.jfk-tooltip-arrowleft .jfk-tooltip-arrowimplbefore,.jfk-tooltip-arrowright .jfk-tooltip-arrowimplbefore{border-color:transparent #fff;top:-6px}.jfk-tooltip-arrowleft .jfk-tooltip-arrowimplafter,.jfk-tooltip-arrowright .jfk-tooltip-arrowimplafter{border-color:transparent #2a2a2a;top:-5px}.jfk-tooltip-arrowleft .jfk-tooltip-arrowimplbefore{border-left-width:0}.jfk-tooltip-arrowleft .jfk-tooltip-arrowimplafter{border-left-width:0;left:1px}.jfk-tooltip-arrowright .jfk-tooltip-arrowimplbefore{border-right-width:0}.jfk-tooltip-arrowright .jfk-tooltip-arrowimplafter{border-right-width:0}.share-client-dialog{max-height:100%;overflow:auto;width:auto!important;-moz-box-sizing:border-box;-webkit-box-sizing:border-box;box-sizing:border-box}* html .share-client-dialog{max-height:none!important;overflow:visible!important}*:first-child+html .share-client-dialog{max-height:none!important;overflow:visible!important}.share-client-dialog .modal-dialog-content{padding:0}.share-client-dialog .modal-dialog-title{padding:0}.share-client-dialog .modal-dialog-title{font-family:arial,sans-serif;font-weight:normal}.share-client-content-iframe{height:100%;width:100%;border:none}.share-client-dialog .modal-dialog-buttons{display:none}.share-client-error-dialog{width:400px}.share-client-loading-contents{height:99px;text-align:center;width:454px}.share-client-spinner{background-image:url(//ssl.gstatic.com/docs/documents/share/images/spinner-1.gif);display:inline-block;margin-top:41px;width:16px;height:16px}.inline-share-ui-status{font-size:12pt;font-weight:bold;height:19px;padding:5px 10px;background-color:#f1f4ff}.inline-share-ui-overlay{position:absolute;z-index:150;background-color:#fff;opacity:0;-ms-filter:"progid:DXImageTransform.Microsoft.Alpha(Opacity=0)"}.share-client-panel-dialog-share{height:100%;width:100%}.share-client-panel-dialog-overlay{position:absolute;z-index:150}.share-client-offscreen{position:absolute!important;left:-10000px!important;top:-10000px!important}.share-client-butterbar-container{font-weight:bold;position:fixed;left:50%;display:inline-block;padding-bottom:5px}.share-client-butterbar-container .jfk-butterBar-shown{height:21px}.share-client-butterbar-top{top:23px}.share-client-butterbar-zindex{z-index:3021}.share-client-butter-icon{opacity:.70;display:inline-block;width:21px;height:21px;padding-bottom:1px;padding-top:1px;margin-right:1px;vertical-align:middle}.share-client-butter-message,.share-client-butter-link{line-height:21px}.share-client-butter-link,.share-client-butter-link:visited{color:#15c;text-decoration:none;cursor:pointer}.share-client-butter-link:focus{outline:none}.share-client-butter-link:active{color:#d14836}.share-client-butter-link:disabled{color:#222;cursor:default}.share-client-copy-icon{background-position:-21px -147px}.share-client-specific-people-icon{background-position:-21px -218px}.share-client-person-link-icon{background-position:0 -21px}.jfk-tooltip{z-index:30000}.scb-container,.scb-icon{display:inline-block}.scb-split-button{-webkit-border-radius:2px 0 0 2px;-moz-border-radius:2px 0 0 2px;border-radius:2px 0 0 2px}.scb-button-icon{margin:-3px 2px 0px -5px;vertical-align:middle!important}.scb-tooltip-contents{color:#fff;font-size:13px;width:300px}.scb-tooltip-title{font-size:14px;font-weight:bold}.scb-tooltip-text{font-weight:normal}.scb-tooltip-icon-container{width:25px;vertical-align:top}.scb-tooltip-separator{border-top:1px solid #555555;margin:2px 0}.jfk-button-standard .scb-button-icon{opacity:.70}.jfk-button-standard.jfk-button-checked .scb-button-icon,.jfk-button-standard.jfk-button-selected .scb-button-icon,.jfk-button-standard.jfk-button-hover .scb-button-icon{opacity:0.9}.jfk-button-standard.jfk-button-disabled .scb-button-icon{opacity:0.333}.scb-public-icon-white,.scb-public-icon-black,.scb-unlisted-icon-white,.scb-unlisted-icon-black,.scb-domain-public-icon-white,.scb-domain-public-icon-black,.scb-domain-unlisted-icon-white,.scb-domain-unlisted-icon-black,.scb-privately-shared-icon-white,.scb-privately-shared-icon-black,.scb-private-icon-white,.scb-private-icon-black{width:21px;height:21px;background-repeat:no-repeat;vertical-align:bottom}.scb-public-icon-black{background-position:-21px -126px}.scb-unlisted-icon-black{background-position:0 -21px}.scb-domain-public-icon-black{background-position:-21px -42px}.scb-domain-unlisted-icon-black{background-position:0 -218px}.scb-privately-shared-icon-black{background-position:-21px -218px}.scb-private-icon-black{background-position:-21px -84px}.scb-public-icon-white{background-position:0 -239px}.scb-unlisted-icon-white{background-position:0 -105px}.scb-domain-public-icon-white{background-position:0 -63px}.scb-domain-unlisted-icon-white{background-position:0 -331px}.scb-privately-shared-icon-white{background-position:-21px -105px}.scb-private-icon-white{background-position:-21px -289px}.share-client-shoutout-promo{width:250px}.share-client-shoutout-promo-title{font-size:15px;font-weight:bold}.share-client-shoutout-promo-warning{color:red;font-weight:bold;font-size:11px}.share-client-shoutout-icon{background-position:-21px -168px;background-repeat:no-repeat;display:inline-block;height:21px;width:21px;margin-top:-3px;vertical-align:middle}.share-client-shoutout-button{min-width:0;-webkit-border-radius:0 2px 2px 0;-moz-border-radius:0 2px 2px 0;border-radius:0 2px 2px 0;z-index:1}.jfk-bubble.jfk-bubble-promo{background-color:#f9edbe;border:1px solid #f0c36d}.jfk-bubble-promo .jfk-bubble-arrowdown .jfk-bubble-arrowimplbefore,.jfk-bubble-promo .jfk-bubble-arrowup .jfk-bubble-arrowimplbefore{border-color:#f0c36d transparent}.jfk-bubble-promo .jfk-bubble-arrowdown .jfk-bubble-arrowimplafter,.jfk-bubble-promo .jfk-bubble-arrowup .jfk-bubble-arrowimplafter{border-color:#f9edbe transparent}.jfk-bubble-promo .jfk-bubble-arrowleft .jfk-bubble-arrowimplbefore,.jfk-bubble-promo .jfk-bubble-arrowright .jfk-bubble-arrowimplbefore{border-color:transparent #f0c36d}.jfk-bubble-promo .jfk-bubble-arrowleft .jfk-bubble-arrowimplafter,.jfk-bubble-promo .jfk-bubble-arrowright .jfk-bubble-arrowimplafter{border-color:transparent #f9edbe}.goog-submenu-arrow{-webkit-transition:all 0.218s;-moz-transition:all 0.218s;-o-transition:all 0.218s;transition:all 0.218s;font-size:70%;left:auto;right:10px;padding-top:3px;padding-right:0;position:absolute;text-align:right;opacity:.5;filter:alpha(opacity=50)}.goog-menuitem-highlight .goog-submenu-arrow,.goog-menuitem-hover .goog-submenu-arrow{-webkit-transition:none;-moz-transition:none;-o-transition:none;transition:none;border-left-color:#999;opacity:1.0}.goog-menuitem-disabled .goog-submenu-arrow{color:inherit;opacity:1.0}.jfk-scrollbar::-webkit-scrollbar{height:16px;overflow:visible;width:16px}.jfk-scrollbar::-webkit-scrollbar-button{height:0;width:0}.jfk-scrollbar::-webkit-scrollbar-track{background-clip:padding-box;border:solid transparent;border-width:0 0 0 4px}.jfk-scrollbar::-webkit-scrollbar-track:horizontal{border-width:4px 0 0}.jfk-scrollbar::-webkit-scrollbar-track:hover{background-color:rgba(0,0,0,.05);box-shadow:inset 1px 0 0 rgba(0,0,0,.1)}.jfk-scrollbar::-webkit-scrollbar-track:horizontal:hover{box-shadow:inset 0 1px 0 rgba(0,0,0,.1)}.jfk-scrollbar::-webkit-scrollbar-track:active{background-color:rgba(0,0,0,.05);box-shadow:inset 1px 0 0 rgba(0,0,0,.14),inset -1px 0 0 rgba(0,0,0,.07)}.jfk-scrollbar::-webkit-scrollbar-track:horizontal:active{box-shadow:inset 0 1px 0 rgba(0,0,0,.14),inset 0 -1px 0 rgba(0,0,0,.07)}.jfk-scrollbar-dark.jfk-scrollbar::-webkit-scrollbar-track:hover{background-color:rgba(255,255,255,.1);box-shadow:inset 1px 0 0 rgba(255,255,255,.2)}.jfk-scrollbar-dark.jfk-scrollbar::-webkit-scrollbar-track:horizontal:hover{box-shadow:inset 0 1px 0 rgba(255,255,255,.2)}.jfk-scrollbar-dark.jfk-scrollbar::-webkit-scrollbar-track:active{background-color:rgba(255,255,255,.1);box-shadow:inset 1px 0 0 rgba(255,255,255,.25),inset -1px 0 0 rgba(255,255,255,.15)}.jfk-scrollbar-dark.jfk-scrollbar::-webkit-scrollbar-track:horizontal:active{box-shadow:inset 0 1px 0 rgba(255,255,255,.25),inset 0 -1px 0 rgba(255,255,255,.15)}.jfk-scrollbar::-webkit-scrollbar-thumb{background-color:rgba(0,0,0,.2);background-clip:padding-box;border:solid transparent;border-width:1px 1px 1px 6px;min-height:28px;padding:100px 0 0;box-shadow:inset 1px 1px 0 rgba(0,0,0,.1),inset 0 -1px 0 rgba(0,0,0,.07)}.jfk-scrollbar::-webkit-scrollbar-thumb:horizontal{border-width:6px 1px 1px;padding:0 0 0 100px;box-shadow:inset 1px 1px 0 rgba(0,0,0,.1),inset -1px 0 0 rgba(0,0,0,.07)}.jfk-scrollbar::-webkit-scrollbar-thumb:hover{background-color:rgba(0,0,0,.4);box-shadow:inset 1px 1px 1px rgba(0,0,0,.25)}.jfk-scrollbar::-webkit-scrollbar-thumb:active{background-color:rgba(0,0,0,0.5);box-shadow:inset 1px 1px 3px rgba(0,0,0,0.35)}.jfk-scrollbar-dark.jfk-scrollbar::-webkit-scrollbar-thumb{background-color:rgba(255,255,255,.3);box-shadow:inset 1px 1px 0 rgba(255,255,255,.15),inset 0 -1px 0 rgba(255,255,255,.1)}.jfk-scrollbar-dark.jfk-scrollbar::-webkit-scrollbar-thumb:horizontal{box-shadow:inset 1px 1px 0 rgba(255,255,255,.15),inset -1px 0 0 rgba(255,255,255,.1)}.jfk-scrollbar-dark.jfk-scrollbar::-webkit-scrollbar-thumb:hover{background-color:rgba(255,255,255,.6);box-shadow:inset 1px 1px 1px rgba(255,255,255,.37)}.jfk-scrollbar-dark.jfk-scrollbar::-webkit-scrollbar-thumb:active{background-color:rgba(255,255,255,.75);box-shadow:inset 1px 1px 3px rgba(255,255,255,.5)}.jfk-scrollbar-borderless.jfk-scrollbar::-webkit-scrollbar-track{border-width:0 1px 0 6px}.jfk-scrollbar-borderless.jfk-scrollbar::-webkit-scrollbar-track:horizontal{border-width:6px 0 1px}.jfk-scrollbar-borderless.jfk-scrollbar::-webkit-scrollbar-track:hover{background-color:rgba(0,0,0,.035);box-shadow:inset 1px 1px 0 rgba(0,0,0,.14),inset -1px -1px 0 rgba(0,0,0,.07)}.jfk-scrollbar-borderless.jfk-scrollbar-dark.jfk-scrollbar::-webkit-scrollbar-track:hover{background-color:rgba(255,255,255,.07);box-shadow:inset 1px 1px 0 rgba(255,255,255,.25),inset -1px -1px 0 rgba(255,255,255,.15)}.jfk-scrollbar-borderless.jfk-scrollbar::-webkit-scrollbar-thumb{border-width:0 1px 0 6px}.jfk-scrollbar-borderless.jfk-scrollbar::-webkit-scrollbar-thumb:horizontal{border-width:6px 0 1px}.jfk-scrollbar::-webkit-scrollbar-corner{background:transparent}body.jfk-scrollbar::-webkit-scrollbar-track-piece{background-clip:padding-box;background-color:#f5f5f5;border:solid #fff;border-width:0 0 0 3px;box-shadow:inset 1px 0 0 rgba(0,0,0,.14),inset -1px 0 0 rgba(0,0,0,.07)}body.jfk-scrollbar::-webkit-scrollbar-track-piece:horizontal{border-width:3px 0 0;box-shadow:inset 0 1px 0 rgba(0,0,0,.14),inset 0 -1px 0 rgba(0,0,0,.07)}body.jfk-scrollbar::-webkit-scrollbar-thumb{border-width:1px 1px 1px 5px}body.jfk-scrollbar::-webkit-scrollbar-thumb:horizontal{border-width:5px 1px 1px}body.jfk-scrollbar::-webkit-scrollbar-corner{background-clip:padding-box;background-color:#f5f5f5;border:solid #fff;border-width:3px 0 0 3px;box-shadow:inset 1px 1px 0 rgba(0,0,0,.14)}.docs-butterbar-container{font-weight:bold;height:0;position:absolute;text-align:center;top:23px;width:100%;z-index:999}.docs-butterbar-container.docs-butterbar-container-compact{top:20px}.docs-butterbar-wrap{display:inline-block;padding-bottom:5px}.docs-butterbar-link,a.docs-butterbar-link:link,a.docs-butterbar-link:visited,.docs-butterbar-link-no-pad,a.docs-butterbar-link-no-pad:link,a.docs-butterbar-link-no-pad:visited{color:#666;cursor:pointer;text-decoration:underline}.docs-butterbar-link,a.docs-butterbar-link:link,a.docs-butterbar-link:visited{padding-left:6px}.jfk-butterBar-warning .docs-butterbar-link,.jfk-butterBar-warning a.docs-butterbar-link:link,.jfk-butterBar-warning a.docs-butterbar-link:visited,.jfk-butterBar-warning .docs-butterbar-link-no-pad,.jfk-butterBar-warning a.docs-butterbar-link-no-pad:link,.jfk-butterBar-warning a.docs-butterbar-link-no-pad:visited{color:#111}.jfk-butterBar-error .docs-butterbar-link,.jfk-butterBar-error a.docs-butterbar-link:link,.jfk-butterBar-error a.docs-butterbar-link:visited,.jfk-butterBar-error .docs-butterbar-link-no-pad,.jfk-butterBar-error a.docs-butterbar-link-no-pad:link,.jfk-butterBar-error a.docs-butterbar-link-no-pad:visited{color:#add8e6}#docs-chrome{background:white;outline:none}#docs-header{position:relative}#docs-header.docs-og-minibar{max-height:50px}.docs-vis-ref-chrome #docs-header.docs-og-minibar{max-height:31px}#docs-bars{position:relative}#docs-titlebar-container{position:relative}.docs-vis-ref-chrome #docs-titlebar-container{margin-left:40px}#docs-branding-container{height:60px;margin-top:26px;position:absolute;width:40px;z-index:1}#docs-branding-container a{display:inline-block;height:60px;width:40px}.docs-og-minibar #docs-branding-container{margin-top:0}#docs-titlebar{clear:both;font-size:20px;height:33px;padding:0;padding-top:19px;width:100%}.docs-vis-ref-chrome #docs-titlebar{font-size:18px;height:24px;padding-top:7px}#docs-header.docs-og-minibar #docs-titlebar{height:29px;padding-top:0}.docs-vis-ref-chrome #docs-header.docs-og-minibar #docs-titlebar{height:24px}#docs-header.docs-og-minibar #docs-titlebar-container{top:-5px}.docs-vis-ref-chrome #docs-header.docs-og-minibar #docs-titlebar-container{top:-21px}#docs-header.docs-og-minibar .docs-titlebar-buttons{top:5px}.docs-vis-ref-chrome #docs-header.docs-og-minibar .docs-titlebar-buttons{top:19px}.docs-exp{border-radius:6px;border:1px solid #800;color:#800;float:left;font-size:11px;margin-right:8px;padding:0 5px;text-align:center;white-space:nowrap}.docs-exp-link{color:#800}#docs-drive-logo{background:url(//ssl.gstatic.com/docs/common/product/drive2.svg) center no-repeat;height:60px;position:absolute;width:40px;opacity:0;-webkit-transition:all 125ms linear;-moz-transition:all 125ms linear;-o-transition:all 125ms linear;transition:all 125ms linear}#docs-branding-logo{height:60px;position:absolute;width:40px;-webkit-transition:all 125ms linear;-moz-transition:all 125ms linear;-o-transition:all 125ms linear;transition:all 125ms linear}#docs-branding-container.docs-branding-default{background-color:#d1d1d1}.docs-branding-default #docs-branding-logo{background:url(//ssl.gstatic.com/docs/common/product/drive2.svg) center no-repeat}#docs-branding-container.docs-branding-documents{background-color:#4285f4}.docs-branding-documents #docs-branding-logo{background:url(//ssl.gstatic.com/docs/common/product/documents1.svg) center no-repeat}#docs-branding-container.docs-branding-spreadsheets{background-color:#0f9d58}.docs-branding-spreadsheets #docs-branding-logo{background:url(//ssl.gstatic.com/docs/common/product/spreadsheets1.svg) center no-repeat}#docs-branding-container.docs-branding-presentations{background-color:#f4b400}.docs-branding-presentations #docs-branding-logo{background:url(//ssl.gstatic.com/docs/common/product/presentations1.svg) center no-repeat}#docs-branding-container.docs-branding-drawings{background-color:#db4437}.docs-branding-drawings #docs-branding-logo{background:url(//ssl.gstatic.com/docs/common/product/drawings1.svg) center no-repeat}#docs-branding-container.docs-branding-forms{background-color:#0f9d58}.docs-branding-forms #docs-branding-logo{background:url(//ssl.gstatic.com/docs/common/product/forms1.svg) center no-repeat}#docs-branding-container.docs-branding-scripts{background-color:#4285f4}.docs-branding-scripts #docs-branding-logo{background:url(//ssl.gstatic.com/docs/common/product/scripts2.svg) center no-repeat}#docs-branding-container:not(.docs-branding-homescreen-enabled):hover #docs-drive-logo{opacity:1}#docs-branding-container:not(.docs-branding-homescreen-enabled):hover #docs-branding-logo{opacity:0}#docs-branding-container.docs-branding-default:hover #docs-drive-logo{opacity:0}#docs-branding-container.docs-branding-default:hover #docs-branding-logo{opacity:1}.docs-butter{text-align:center}.docs-butter-inner{border-radius:3px;font-size:13px;font-weight:bold;margin:0 auto 5px;padding:5px 7px}.docs-butter-info{background:#f6bc5d;color:#222}.docs-butter-info-link{color:#0658b5}.docs-butter-warning{background:#c00;color:#fff}.docs-butter-warning-link{color:#c3d9ff}.docs-fading-toolbar-message{background-color:#fff;border:#999 solid;border-width:0px 0px 1px 0px;color:#999;font:28px Arial,sans-serif;position:absolute;text-align:center}.docs-title-outer{margin-left:12px;white-space:nowrap}.docs-vis-ref-chrome .docs-title-outer{margin-left:17px}.docs-title{display:inline-block;max-width:99%;outline:none}.docs-vis-ref-chrome .docs-title{max-width:none}.docs-title-inner{font-size:20px;margin-top:1px;max-width:600px;margin:2px 4px 1px 3px;overflow:hidden;text-overflow:ellipsis}.docs-vis-ref-chrome .docs-title-inner{color:#333;font-size:18px}.docs-title-untitled{font-style:italic;opacity:.5}.docs-vis-ref-chrome .docs-title-untitled{color:#777;opacity:1}.docs-title-widget{height:27px;width:auto}.docs-title-widget-enabled:hover .docs-title{background-color:#eee;cursor:pointer}.docs-title-widget .docs-back-container a{display:none}.docs-title-widget:hover .docs-back-container a{display:inline-block}.docs-back-container{height:21px;opacity:0.6;padding-right:9px;margin-top:1px;vertical-align:top;width:21px}.docs-back-container:hover{opacity:0.9}.docs-star-container,.docs-folder-container,.docs-activity-indicator-container{height:29px;margin-top:2px;vertical-align:top;padding-right:2px}#docs-star,#docs-folder,#docs-activity-indicator,.docs-title-save-label{margin-left:4px;outline:none}#docs-star{padding-top:1px}#docs-activity-indicator{padding-left:4px;padding-top:2px}#docs-folder .docs-icon-img{opacity:0.45}#docs-folder.goog-control-hover .docs-icon-img{opacity:0.55}#docs-folder.goog-control-active .docs-icon-img,#docs-folder.goog-control-open .docs-icon-img{opacity:0.65}#docs-star.jfk-star-hover,#docs-folder.goog-control-hover .docs-icon-img{cursor:pointer}#docs-star,#docs-folder .docs-icon{vertical-align:baseline}.docs-debug-info,.docs-debug-info a{color:#777!important;font-size:10px}.docs-debug-container{margin-right:6px;vertical-align:top}.docs-titlebar-buttons{padding:0 44px 0 0;position:absolute;right:0;text-align:right;top:29px;vertical-align:middle;white-space:nowrap}.docs-vis-ref-chrome .docs-titlebar-buttons{top:26px}.docs-titlebar-button,.docs-debug-container{z-index:1}#docs-docos-commentsbutton{margin-right:9px}#docs-titlebar-save{text-align:center}#docs-docos-commentsbutton,#docs-titlebar-share-client-button div{height:24px;padding-bottom:3px;vertical-align:middle}#docs-titlebar-share-client-button div.jfk-button{margin-right:0}#docs-docos-commentsbutton{cursor:default}.docs-titlebar-share-label .goog-imageless-button-content{padding-right:6px}.docs-titlebar-share-label .goog-custom-button-inner-box{padding-left:10px;padding-right:6px}.docs-titlebar-buttons .goog-menu-button-dropdown{position:relative;top:2px;vertical-align:baseline}.docs-menubar{cursor:default;display:inline-block;font:13px Arial,sans-serif;height:35px;margin-left:39px;outline:none;position:relative;white-space:nowrap}.docs-vis-ref-chrome .docs-menubar{height:29px;margin-left:52px}.docs-menubar .goog-control{padding:5px 7px;border:1px solid transparent;outline:none}.docs-menubar .goog-control-hover{background:#eee;border-color:#eee}.docs-menubar .goog-control-open{background:#fff;border:1px solid #ccc;border:1px solid rgba(0,0,0,.2);border-bottom:none;-moz-box-shadow:0 2px 4px rgba(0,0,0,0.2);-webkit-box-shadow:0 2px 4px rgba(0,0,0,0.2);box-shadow:0 2px 4px rgba(0,0,0,0.2);color:black;z-index:1001}.docs-menubar .goog-control-disabled{color:#ccc}#docs-editor-container{background:#ebebeb;padding:0}.docs-vis-ref-editor-container{background:#eee}#docs-editor{background:#ebebeb;outline:none}.docs-vis-ref-editor-container #docs-editor{background:#eee}.docs-gaia-disabled{color:#999;cursor:text}.docs-hide-label{display:none}.docs-title-save-label{color:#6a6a6a;display:inline-block;margin-left:24px;max-width:250px;overflow:hidden;text-overflow:ellipsis;vertical-align:text-bottom;white-space:nowrap}.docs-vis-ref-chrome .docs-title-save-label{color:#777;margin-left:14px}.docs-title-save-label:hover,.docs-title-save-label-focused{cursor:pointer;text-decoration:underline}.docs-title-save-label-disabled:hover{cursor:auto;text-decoration:none}.docs-rename-dialog,.docs-edit-description-dialog{width:340px}.docs-rename-dialog .modal-dialog-userInput,.docs-edit-description-dialog .modal-dialog-userInput{width:300px}#docs-help-anchor{left:30%;position:absolute}#docs-help-anchor-right{right:0;position:absolute}.docs-faux-link{color:#20c;cursor:pointer;text-decoration:underline}.docs-offscreen{position:absolute;left:-10000px;top:-10000px}.modal-dialog-bg{z-index:1000}.modal-dialog{z-index:1001}.goog-menu{z-index:1001}#docs-menu-shield{background-color:#fff;position:absolute;z-index:1002}.docs-menu-hide-mnemonics .goog-menuitem-mnemonic-hint{text-decoration:none}.docs-menu-hide-mnemonics .goog-menuitem-mnemonic-separator{display:none}input{font-family:inherit}.collections-bubble-header{font-weight:bold}.collections-bubble-list{padding:5px 0}.collections-bubble-none{color:#999;padding-left:20px}.collections-bubble-row{padding-top:5px}.collections-bubble-row .docs-icon{opacity:0.4;position:relative;top:-4px}.collections-bubble-row a:visited{color:#15c}body{background-color:white;color:black;font:normal 13px arial,sans-serif;margin:0}.jfk-activityIndicator{display:inline-block;position:relative;direction:ltr}.jfk-activityIndicator,.jfk-activityIndicator-icon,.jfk-activityIndicator-circle,.jfk-activityIndicator-circle-transition{height:19px;width:19px}.jfk-activityIndicator-small.jfk-activityIndicator,.jfk-activityIndicator-small .jfk-activityIndicator-icon,.jfk-activityIndicator-small .jfk-activityIndicator-circle,.jfk-activityIndicator-small .jfk-activityIndicator-circle-transition{height:16px;width:16px}.jfk-activityIndicator-icon{background:url(//ssl.gstatic.com/ui/v1/activityindicator/offline.png) center no-repeat}.jfk-activityIndicator-small .jfk-activityIndicator-icon{background:url(//ssl.gstatic.com/ui/v1/activityindicator/offline_16.png) center no-repeat}.jfk-activityIndicator-icon{-webkit-transition:opacity .218s linear .44s;-moz-transition:opacity .218s linear .44s;-o-transition:opacity .218s linear .44s;transition:opacity .218s linear .44s;top:0;left:0;position:absolute;opacity:0}.jfk-activityIndicator-circle{-webkit-border-radius:50%;-moz-border-radius:50%;border-radius:50%;top:0;left:0;position:absolute}.jfk-activityIndicator-mask{overflow:hidden;position:absolute}.jfk-activityIndicator-circle-transition{position:relative}.jfk-activityIndicator-transition{-webkit-transition:all .22s ease-in;-moz-transition:all .22s ease-in;-o-transition:all .22s ease-in;transition:all .22s ease-in}.jfk-activityIndicator-transition-second{-webkit-transition:all .22s ease-out .22s;-moz-transition:all .22s ease-out .22s;-o-transition:all .22s ease-out .22s;transition:all .22s ease-out .22s}.jfk-checkbox{-webkit-border-radius:1px;-moz-border-radius:1px;border-radius:1px;background-color:rgba(255,255,255,.05);border:1px solid #c6c6c6;border:1px solid rgba(155,155,155,.57);font-size:1px;height:11px;margin:0px 4px 0px 1px;outline:0;vertical-align:text-bottom;width:11px}.jfk-checkbox-undetermined{background-color:#fff;background-color:rgba(255,255,255,.65)}.jfk-checkbox-checked{background-color:#fff;background-color:rgba(255,255,255,.65)}.jfk-checkbox-hover{-webkit-box-shadow:inset 0px 1px 1px rgba(0,0,0,.1);-moz-box-shadow:inset 0px 1px 1px rgba(0,0,0,.1);box-shadow:inset 0px 1px 1px rgba(0,0,0,.1);border:1px solid #b2b2b2}.jfk-checkbox-active{background-color:#ebebeb}.jfk-checkbox-focused{border:1px solid #4d90fe}.jfk-checkbox-clearOutline.jfk-checkbox-focused{border:1px solid #c6c6c6;border:1px solid rgba(155,155,155,.57)}.jfk-checkbox-disabled,.jfk-checkbox-clearOutline.jfk-checkbox-disabled{background-color:#fff;border:1px solid #f1f1f1;cursor:default}.jfk-checkbox-checkmark{height:15px;outline:0;width:15px;left:0;position:relative;top:-3px}.jfk-checkbox-undetermined .jfk-checkbox-checkmark{background:url(//ssl.gstatic.com/ui/v1/menu/checkmark-partial.png) no-repeat -5px -3px;background-image:-webkit-image-set(url(//ssl.gstatic.com/ui/v1/menu/checkmark-partial.png) 1x,url(//ssl.gstatic.com/ui/v1/menu/checkmark-partial_2x.png) 2x)}.jfk-checkbox-checked .jfk-checkbox-checkmark{background:url(//ssl.gstatic.com/ui/v1/menu/checkmark.png) no-repeat -5px -3px;background-image:-webkit-image-set(url(//ssl.gstatic.com/ui/v1/menu/checkmark.png) 1x,url(//ssl.gstatic.com/ui/v1/menu/checkmark_2x.png) 2x)}.jfk-textinput{-webkit-border-radius:1px;-moz-border-radius:1px;border-radius:1px;border:1px solid #d9d9d9;border-top:1px solid #c0c0c0;font-size:13px;height:25px;padding:1px 8px}.jfk-textinput:focus{-webkit-box-shadow:inset 0 1px 2px rgba(0,0,0,0.3);-moz-box-shadow:inset 0 1px 2px rgba(0,0,0,0.3);box-shadow:inset 0 1px 2px rgba(0,0,0,0.3);border:1px solid #4d90fe;outline:none}.jfk-textinput::-ms-clear{display:none}.jfk-radiobutton{display:inline-block;outline:none;padding:5px 7px;position:relative}.jfk-radiobutton-radio{-webkit-border-radius:50%;-moz-border-radius:50%;border-radius:50%;-webkit-box-sizing:border-box;-moz-box-sizing:border-box;box-sizing:border-box;background:url(//ssl.gstatic.com/ui/v1/radiobutton/unchecked.png) -3px -3px;background:rgba(255,255,255,0);border:1px solid rgba(198,198,198,1);height:15px;left:7px;margin:0;outline:none;position:absolute;text-align:left;top:6px;width:15px}.jfk-radiobutton:active .jfk-radiobutton-radio{background:rgba(235,235,235,1);border-color:rgba(182,182,182,1)}.jfk-radiobutton:hover .jfk-radiobutton-radio{-webkit-box-shadow:inset 0 1px 1px rgba(0,0,0,.1);-moz-box-shadow:inset 0 1px 1px rgba(0,0,0,.1);box-shadow:inset 0 1px 1px rgba(0,0,0,.1);border-color:rgba(182,182,182,1)}.jfk-radiobutton:focus .jfk-radiobutton-radio{border-color:rgba(77,144,254,1)}.jfk-radiobutton-checked .jfk-radiobutton-radio{background:url(//ssl.gstatic.com/ui/v1/radiobutton/checked.png) -3px -3px;background:rgba(255,255,255,0)}.jfk-radiobutton.jfk-radiobutton:focus .jfk-radiobutton-radio{background:url(//ssl.gstatic.com/ui/v1/radiobutton/unchecked_focused.png) -3px -3px;background:rgba(255,255,255,0)}.jfk-radiobutton-checked.jfk-radiobutton:focus .jfk-radiobutton-radio{background:url(//ssl.gstatic.com/ui/v1/radiobutton/checked_focused.png) -3px -3px;background:rgba(255,255,255,0)}.jfk-radiobutton-checked .jfk-radiobutton-radio::after{-webkit-border-radius:50%;-moz-border-radius:50%;border-radius:50%;background:rgba(96,96,96,1);content:'';display:block;height:7px;left:3px;position:relative;top:3px;width:7px}.jfk-radiobutton .jfk-radiobutton-label{cursor:default;margin-left:22px}.jfk-radiobutton-disabled .jfk-radiobutton-radio{background:url(//ssl.gstatic.com/ui/v1/radiobutton/unchecked-disabled.png) -3px -3px;background:rgba(255,255,255,0);border-color:rgba(241,241,241,1)}.jfk-radiobutton-disabled.jfk-radiobutton-checked .jfk-radiobutton-radio{background:url(//ssl.gstatic.com/ui/v1/radiobutton/checked-disabled.png) -3px -3px;background:rgba(255,255,255,0)}.jfk-radiobutton-disabled.jfk-radiobutton-checked .jfk-radiobutton-radio::after{background:rgba(184,184,184,1)}.jfk-radiobutton-disabled .jfk-radiobutton-label{color:rgb(184,184,184)}.jfk-radiobutton-disabled:active .jfk-radiobutton-radio,.jfk-radiobutton-disabled:hover .jfk-radiobutton-radio{-webkit-box-shadow:none;-moz-box-shadow:none;box-shadow:none;background:rgba(255,255,255,1);border-color:rgba(241,241,241,1)}::-webkit-scrollbar{height:16px;overflow:visible;width:16px}::-webkit-scrollbar-button{height:0;width:0}::-webkit-scrollbar-track{background-clip:padding-box;border:solid transparent;border-width:0 0 0 4px}::-webkit-scrollbar-track:horizontal{border-width:4px 0 0}::-webkit-scrollbar-track:hover{background-color:rgba(0,0,0,.05);box-shadow:inset 1px 0 0 rgba(0,0,0,.1)}::-webkit-scrollbar-track:horizontal:hover{box-shadow:inset 0 1px 0 rgba(0,0,0,.1)}::-webkit-scrollbar-track:active{background-color:rgba(0,0,0,.05);box-shadow:inset 1px 0 0 rgba(0,0,0,.14),inset -1px 0 0 rgba(0,0,0,.07)}::-webkit-scrollbar-track:horizontal:active{box-shadow:inset 0 1px 0 rgba(0,0,0,.14),inset 0 -1px 0 rgba(0,0,0,.07)}.jfk-scrollbar-dark::-webkit-scrollbar-track:hover{background-color:rgba(255,255,255,.1);box-shadow:inset 1px 0 0 rgba(255,255,255,.2)}.jfk-scrollbar-dark::-webkit-scrollbar-track:horizontal:hover{box-shadow:inset 0 1px 0 rgba(255,255,255,.2)}.jfk-scrollbar-dark::-webkit-scrollbar-track:active{background-color:rgba(255,255,255,.1);box-shadow:inset 1px 0 0 rgba(255,255,255,.25),inset -1px 0 0 rgba(255,255,255,.15)}.jfk-scrollbar-dark::-webkit-scrollbar-track:horizontal:active{box-shadow:inset 0 1px 0 rgba(255,255,255,.25),inset 0 -1px 0 rgba(255,255,255,.15)}::-webkit-scrollbar-thumb{background-color:rgba(0,0,0,.2);background-clip:padding-box;border:solid transparent;border-width:1px 1px 1px 6px;min-height:28px;padding:100px 0 0;box-shadow:inset 1px 1px 0 rgba(0,0,0,.1),inset 0 -1px 0 rgba(0,0,0,.07)}::-webkit-scrollbar-thumb:horizontal{border-width:6px 1px 1px;padding:0 0 0 100px;box-shadow:inset 1px 1px 0 rgba(0,0,0,.1),inset -1px 0 0 rgba(0,0,0,.07)}::-webkit-scrollbar-thumb:hover{background-color:rgba(0,0,0,.4);box-shadow:inset 1px 1px 1px rgba(0,0,0,.25)}::-webkit-scrollbar-thumb:active{background-color:rgba(0,0,0,0.5);box-shadow:inset 1px 1px 3px rgba(0,0,0,0.35)}.jfk-scrollbar-dark::-webkit-scrollbar-thumb{background-color:rgba(255,255,255,.3);box-shadow:inset 1px 1px 0 rgba(255,255,255,.15),inset 0 -1px 0 rgba(255,255,255,.1)}.jfk-scrollbar-dark::-webkit-scrollbar-thumb:horizontal{box-shadow:inset 1px 1px 0 rgba(255,255,255,.15),inset -1px 0 0 rgba(255,255,255,.1)}.jfk-scrollbar-dark::-webkit-scrollbar-thumb:hover{background-color:rgba(255,255,255,.6);box-shadow:inset 1px 1px 1px rgba(255,255,255,.37)}.jfk-scrollbar-dark::-webkit-scrollbar-thumb:active{background-color:rgba(255,255,255,.75);box-shadow:inset 1px 1px 3px rgba(255,255,255,.5)}.jfk-scrollbar-borderless::-webkit-scrollbar-track{border-width:0 1px 0 6px}.jfk-scrollbar-borderless::-webkit-scrollbar-track:horizontal{border-width:6px 0 1px}.jfk-scrollbar-borderless::-webkit-scrollbar-track:hover{background-color:rgba(0,0,0,.035);box-shadow:inset 1px 1px 0 rgba(0,0,0,.14),inset -1px -1px 0 rgba(0,0,0,.07)}.jfk-scrollbar-borderless.jfk-scrollbar-dark::-webkit-scrollbar-track:hover{background-color:rgba(255,255,255,.07);box-shadow:inset 1px 1px 0 rgba(255,255,255,.25),inset -1px -1px 0 rgba(255,255,255,.15)}.jfk-scrollbar-borderless::-webkit-scrollbar-thumb{border-width:0 1px 0 6px}.jfk-scrollbar-borderless::-webkit-scrollbar-thumb:horizontal{border-width:6px 0 1px}::-webkit-scrollbar-corner{background:transparent}body::-webkit-scrollbar-track-piece{background-clip:padding-box;background-color:#f5f5f5;border:solid #fff;border-width:0 0 0 3px;box-shadow:inset 1px 0 0 rgba(0,0,0,.14),inset -1px 0 0 rgba(0,0,0,.07)}body::-webkit-scrollbar-track-piece:horizontal{border-width:3px 0 0;box-shadow:inset 0 1px 0 rgba(0,0,0,.14),inset 0 -1px 0 rgba(0,0,0,.07)}body::-webkit-scrollbar-thumb{border-width:1px 1px 1px 5px}body::-webkit-scrollbar-thumb:horizontal{border-width:5px 1px 1px}body::-webkit-scrollbar-corner{background-clip:padding-box;background-color:#f5f5f5;border:solid #fff;border-width:3px 0 0 3px;box-shadow:inset 1px 1px 0 rgba(0,0,0,.14)}.jfk-star{display:inline-block;height:19px;text-align:center;width:19px;padding:2px}.jfk-star:before{content:url(//ssl.gstatic.com/ui/v1/star/star4.png);content:-webkit-image-set(url(//ssl.gstatic.com/ui/v1/star/star4.png) 1x,url(//ssl.gstatic.com/ui/v1/star/star4_2x.png) 2x)}.jfk-star-hover:before{content:url(//ssl.gstatic.com/ui/v1/star/star-hover4.png);content:-webkit-image-set(url(//ssl.gstatic.com/ui/v1/star/star-hover4.png) 1x,url(//ssl.gstatic.com/ui/v1/star/star-hover4_2x.png) 2x)}.jfk-star-active:before{content:url(//ssl.gstatic.com/ui/v1/star/star-active4.png);content:-webkit-image-set(url(//ssl.gstatic.com/ui/v1/star/star-active4.png) 1x,url(//ssl.gstatic.com/ui/v1/star/star-active4_2x.png) 2x)}.jfk-star-checked:before{content:url(//ssl.gstatic.com/ui/v1/star/star-lit4.png);content:-webkit-image-set(url(//ssl.gstatic.com/ui/v1/star/star-lit4.png) 1x,url(//ssl.gstatic.com/ui/v1/star/star-lit4_2x.png) 2x)}.jfk-star-checked.jfk-star-hover:before{content:url(//ssl.gstatic.com/ui/v1/star/star-lit-hover4.png);content:-webkit-image-set(url(//ssl.gstatic.com/ui/v1/star/star-lit-hover4.png) 1x,url(//ssl.gstatic.com/ui/v1/star/star-lit-hover4_2x.png) 2x)}.jfk-star-checked.jfk-star-active:before{content:url(//ssl.gstatic.com/ui/v1/star/star-lit-active4.png);content:-webkit-image-set(url(//ssl.gstatic.com/ui/v1/star/star-lit-active4.png) 1x,url(//ssl.gstatic.com/ui/v1/star/star-lit-active4_2x.png) 2x)}a{text-decoration:none}a:link{color:#15c}a:visited{color:#61c}a:active{color:#d14836}a:hover{text-decoration:underline}.docs-icon{direction:ltr;text-align:left;height:21px;overflow:hidden;vertical-align:middle;width:21px}.docs-icon-img:before{content:url("//ssl.gstatic.com/docs/common/jfk_sprite111.png")}.docs-icon-img{*background:url("//ssl.gstatic.com/docs/common/jfk_sprite111.png")}.docs-icon-img-legacy{background:url("//ssl.gstatic.com/docs/common/jfk_sprite111.png")}.docs-icon-img-container{height:3003px;position:absolute;width:42px}.goog-color-menu-button-indicator .docs-icon{height:19px}.goog-menuitem-icon .docs-icon-img-container{opacity:.70}.goog-menuitem-icon .docs-icon-document,.goog-menuitem-icon .docs-icon-punch,.goog-menuitem-icon .docs-icon-presentation,.goog-menuitem-icon .docs-icon-spreadsheet,.goog-menuitem-icon .docs-icon-form,.goog-menuitem-icon .docs-icon-drawing,.goog-menuitem-icon .docs-icon-script{opacity:1}.docs-icon-save{left:0;top:-189px}.docs-icon-print{left:0;top:-1932px}.docs-icon-undo,.docs-icon-redo-rtl{left:-21px;top:-2688px}.docs-icon-redo,.docs-icon-undo-rtl{left:0;top:-210px}.docs-icon-copy{left:-21px;top:-1827px}.docs-icon-cut{left:-21px;top:-189px}.docs-icon-paste{left:0;top:-546px}.docs-icon-document{left:0;top:-1323px}.docs-icon-presentation{left:0;top:-168px}.docs-icon-punch{left:0;top:-168px}.docs-icon-spreadsheet{left:-21px;top:-1974px}.docs-icon-form{left:0;top:-987px}.docs-icon-drawing{left:-21px;top:-2163px}.docs-icon-drawing-black{left:0;top:-2100px}.docs-icon-script{left:0;top:-672px}.docs-icon-insert-script{left:0;top:-2961px}.docs-icon-gadget{left:0;top:-588px}.docs-icon-image{left:-21px;top:-588px}.docs-icon-clipboard{left:-21px;top:-2793px}.docs-icon-bold{left:-21px;top:-1911px}.docs-icon-italic{left:0;top:-777px}.docs-icon-text-color{left:0;top:-1134px}.docs-icon-align-left{left:0;top:-735px}.docs-icon-align-center{left:0;top:-357px}.docs-icon-align-right{left:-21px;top:-1239px}.docs-icon-align-justify{left:0;top:-1428px}.docs-icon-valign-top{left:0;top:-2625px}.docs-icon-valign-middle{left:0;top:-1575px}.docs-icon-valign-bottom{left:0;top:-1365px}.docs-icon-list-number{left:-21px;top:-2436px}.docs-icon-list-bullet{left:0;top:-2730px}.docs-icon-indent{left:-21px;top:-1554px}.docs-icon-outdent{left:0;top:-2667px}.docs-icon-line-spacing{left:0;top:-1029px}.docs-icon-underline{left:0;top:-315px}.docs-icon-text-bgcolor{left:-21px;top:-2331px}.docs-icon-textbox{left:0;top:-2478px}.docs-icon-shapes{left:0;top:-2751px}.docs-icon-line-width{left:0;top:-1743px}.docs-icon-add-trendline{left:-21px;top:-1155px}.docs-icon-next{left:-21px;top:-2058px}.docs-icon-previous{left:-21px;top:-1050px}.docs-icon-no-color{left:0;top:-2835px}.docs-icon-fill-color{left:0;top:-1197px}.docs-icon-line-color{left:0;top:-336px}.docs-icon-line-type{left:-21px;top:-147px}.docs-icon-table{left:0;top:-2016px}.docs-icon-comment{left:0;top:-441px}.docs-icon-comment-blank{left:-21px;top:-630px}.docs-icon-comment-blank-highlighted{left:0;top:-1596px}.docs-icon-chart{left:-21px;top:-777px}.docs-icon-list-number-rtl{left:-21px;top:-1323px}.docs-icon-list-bullet-rtl{left:0;top:-2541px}.docs-icon-indent-rtl{left:-21px;top:-1722px}.docs-icon-outdent-rtl{left:0;top:-903px}.docs-icon-line-spacing-rtl{left:-21px;top:-2499px}.docs-icon-text-ltr{left:-21px;top:-315px}.docs-icon-text-rtl{left:0;top:-2268px}.docs-icon-sheet-rtl{left:0;top:-2688px}.docs-icon-share{left:0;top:-1092px}.docs-icon-subscript{left:0;top:-2898px}.docs-icon-superscript{left:-21px;top:-714px}.docs-icon-strikethrough{left:-21px;top:-1932px}.docs-icon-clear-formatting{left:0;top:-1155px}.docs-icon-link{left:0;top:-2709px}.docs-icon-special-character{left:0;top:-2499px}.docs-icon-close-white{left:-21px;top:-462px}.docs-icon-close-small{left:0;top:-630px}.docs-icon-paint-format{left:0;top:0}.docs-icon-video{left:-21px;top:-525px}.docs-icon-reload{left:0;top:-1806px}.docs-icon-reload-rtl{left:0;top:-147px}.docs-icon-insert-page-break{left:-21px;top:-2142px}.docs-icon-close{left:-21px;top:-1449px}.docs-icon-check{left:-21px;top:-1638px}.docs-icon-up{left:-21px;top:-168px}.docs-icon-down{left:-21px;top:-1533px}.docs-icon-add-page{left:-21px;top:-420px}.docs-icon-email{left:0;top:-1638px}.docs-icon-insert-equation{left:0;top:-2184px}.docs-icon-insert-horizontal-line{left:0;top:-2226px}.docs-icon-tabstop-center{left:0;top:-273px}.docs-icon-tabstop-center-bottom{left:-21px;top:-504px}.docs-icon-tabstop-left{left:-21px;top:-987px}.docs-icon-tabstop-right{left:0;top:-924px}.docs-icon-border-all{left:0;top:-882px}.docs-icon-border-right{left:0;top:-21px}.docs-icon-border-left{left:0;top:-2436px}.docs-icon-border-top{left:0;top:-420px}.docs-icon-border-bottom{left:-21px;top:-1806px}.docs-icon-border-outside{left:0;top:-2772px}.docs-icon-border-inside{left:-21px;top:-2520px}.docs-icon-border-none{left:-21px;top:-2940px}.docs-icon-border-horizontal{left:0;top:-1680px}.docs-icon-border-vertical{left:0;top:-1554px}.docs-icon-merge{left:-21px;top:-2310px}.docs-icon-wrap{left:0;top:-1407px}.docs-icon-autofilter{left:0;top:-609px}.docs-icon-autofilter-filled{left:0;top:-2163px}.docs-icon-insert-function{left:0;top:-504px}.docs-icon-insert-formula{left:0;top:-1827px}.docs-icon-folder-shared{left:-21px;top:-2562px}.docs-icon-folder-outline{left:0;top:-2121px}.docs-icon-folder-outline-hover{left:-21px;top:-861px}.docs-icon-folder-outline-pressed{left:-21px;top:-2079px}.docs-icon-folder-solid{left:-21px;top:-1785px}.docs-icon-drive{left:0;top:-63px}.docs-icon-drive-grey{left:-21px;top:0}.docs-icon-drive-grey-hover{left:0;top:-483px}.docs-icon-drive-grey-pressed{left:-21px;top:-1029px}.docs-icon-drive-hover{left:0;top:-1470px}.docs-icon-drive-pressed{left:0;top:-2856px}.docs-icon-drive-large{left:0;top:-819px}.docs-icon-back{left:0;top:-1302px}.docs-icon-back-rtl{left:-21px;top:-1302px}.docs-icon-arrow-more{left:0;top:-84px}.docs-icon-arrow-more-rtl{left:-21px;top:-1512px}.docs-icon-search-this-document{left:0;top:-2352px}.docs-icon-arrow-dropdown{left:0;top:-966px}.docs-icon-word-art{left:-21px;top:-84px}.docs-icon-delete-x{left:-21px;top:-1386px}.docs-icon-settings{left:0;top:-2877px}.docs-icon-drive-large-wrapper{width:42px;height:42px}.docs-icon-plus{left:0;top:-126px}.docs-icon-plus-white{left:0;top:-1239px}.docs-icon-alert{left:0;top:-756px}.docs-icon-trash{left:-21px;top:-2961px}.docs-icon-locked{left:-21px;top:-1071px}.docs-icon-unlocked{left:0;top:-2037px}.docs-icon-add-fonts{left:-21px;top:-2415px}.docs-icon-enter-compact{left:0;top:-2919px}.docs-icon-exit-compact{left:0;top:-2646px}.docs-icon-mode-edit{left:0;top:-2205px}.docs-icon-mode-review{left:0;top:-525px}.docs-icon-mode-review-white{left:0;top:-105px}.docs-icon-mode-view{left:-21px;top:-126px}.docs-icon-chat{left:-21px;top:-1890px}.docs-icon-star{left:0;top:-2562px}.docs-icon-duplicate{left:0;top:-1890px}.docs-icon-file{left:-21px;top:-882px}.docs-icon-opacity{left:-21px;top:-1470px}.docs-icon-label-slant{left:-21px;top:-252px}.docs-icon-point-size{left:0;top:-1113px}.docs-icon-question{left:-21px;top:-1575px}.docs-icon-vertical-gridlines{left:-21px;top:-2289px}.docs-icon-left-axis{left:-21px;top:-903px}.docs-icon-right-axis{left:0;top:-2394px}.docs-icon-left-axis-gridlines{left:0;top:-2415px}.docs-icon-right-axis-gridlines{left:0;top:-2940px}.docs-icon-reset{left:0;top:-2583px}.docs-icon-drag-move{left:0;top:-1701px}.docs-icon-col-dragger{left:0;top:-378px}.docs-icon-chrome-store{left:0;top:-231px}.docs-icon-fit-area{left:0;top:-1260px}.docs-icon-zoom-out{left:0;top:-1764px}.docs-icon-zoom-tool{left:-21px;top:-672px}.docs-icon-download{left:0;top:-1512px}.docs-icon-fusion-table{left:-21px;top:-231px}.docs-icon-spreadsheet-sink{left:-21px;top:-693px}.docs-icon-send-responses{left:0;top:-1785px}.docs-icon-liveform{left:-21px;top:-483px}.docs-icon-ellipsis{left:0;top:-1869px}.docs-icon-html-preview{left:0;top:-2079px}.docs-icon-grid{left:0;top:-2793px}.docs-icon-add-animation{left:-21px;top:-1995px}.docs-icon-playhead{left:-21px;top:-378px}.docs-icon-playhead-rtl{left:-21px;top:-210px}.docs-icon-unsupported{left:-21px;top:-2982px}.docs-icon-calendar{left:0;top:-1449px}.docs-zippy-closed{left:-21px;top:-2709px}.docs-zippy-open{left:0;top:-252px}.docs-icon-bookmark{left:-21px;top:-399px}.docs-icon-heading{left:-21px;top:-2751px}.docs-icon-file-blue{left:0;top:-1974px}.docs-icon-web-result{left:-21px;top:-2016px}.docs-icon-mic{left:-21px;top:-42px}.docs-icon-paragraph{left:0;top:-798px}.docs-icon-bookmark-black{left:0;top:-294px}.docs-icon-web-result-blue{left:0;top:-2247px}.docs-icon-popout{left:-21px;top:-1659px}.docs-icon-checkbox-type{left:-21px;top:-924px}.docs-icon-dropdown-type{left:-21px;top:-1218px}.docs-icon-grid-type{left:-21px;top:-2877px}.docs-icon-image-type{left:0;top:-1050px}.docs-icon-radio-type{left:-21px;top:-1428px}.docs-icon-scale-type{left:0;top:-693px}.docs-icon-text-type{left:-21px;top:-2205px}.docs-icon-time-type{left:-21px;top:-63px}.docs-icon-insert-text-block{left:-21px;top:-1113px}.docs-icon-accepting-responses-on{left:0;top:-42px}.docs-icon-accepting-responses-off{left:0;top:-2520px}.docs-icon-decimal-increase{left:0;top:-1995px}.docs-icon-decimal-decrease{left:-21px;top:-651px}.docs-icon-settings-white{left:-21px;top:-1260px}.docs-icon-no-symbol{left:0;top:-1848px}.docs-icon-crop{left:0;top:-1386px}.docs-icon-green-check{left:-21px;top:-1869px}@media screen and (-webkit-device-pixel-ratio:2){.docs-icon-img{content:url("//ssl.gstatic.com/docs/common/jfk_sprite_hdpi49.png")}.docs-icon-img-container{height:3066px;position:absolute;width:42px}.docs-icon-save{left:0;top:-1344px}.docs-icon-print{left:0;top:-378px}.docs-icon-undo,.docs-icon-redo-rtl{left:0;top:-1659px}.docs-icon-redo,.docs-icon-undo-rtl{left:-21px;top:-2415px}.docs-icon-copy{left:0;top:-1554px}.docs-icon-cut{left:-21px;top:-2667px}.docs-icon-paste{left:0;top:-105px}.docs-icon-document{left:-21px;top:-63px}.docs-icon-presentation{left:-21px;top:-567px}.docs-icon-punch{left:-21px;top:-567px}.docs-icon-spreadsheet{left:-21px;top:-2142px}.docs-icon-form{left:-21px;top:-1155px}.docs-icon-drawing{left:0;top:-1995px}.docs-icon-drawing-black{left:0;top:-2331px}.docs-icon-script{left:-21px;top:-2751px}.docs-icon-insert-script{left:0;top:-756px}.docs-icon-gadget{left:-21px;top:-1575px}.docs-icon-image{left:-21px;top:-1491px}.docs-icon-clipboard{left:0;top:-2058px}.docs-icon-bold{left:0;top:-1848px}.docs-icon-italic{left:0;top:-63px}.docs-icon-text-color{left:-21px;top:-1029px}.docs-icon-align-left{left:-21px;top:-1722px}.docs-icon-align-center{left:0;top:-231px}.docs-icon-align-right{left:0;top:-1386px}.docs-icon-align-justify{left:-21px;top:-1680px}.docs-icon-valign-top{left:-21px;top:-252px}.docs-icon-valign-middle{left:0;top:-1071px}.docs-icon-valign-bottom{left:0;top:-42px}.docs-icon-list-number{left:0;top:-1260px}.docs-icon-list-bullet{left:-21px;top:-1050px}.docs-icon-indent{left:0;top:-2709px}.docs-icon-outdent{left:0;top:-714px}.docs-icon-line-spacing{left:-21px;top:-966px}.docs-icon-underline{left:-21px;top:-1428px}.docs-icon-text-bgcolor{left:0;top:-1764px}.docs-icon-textbox{left:-21px;top:-1365px}.docs-icon-shapes{left:0;top:-777px}.docs-icon-line-width{left:0;top:-1890px}.docs-icon-add-trendline{left:-21px;top:-1092px}.docs-icon-next{left:0;top:-525px}.docs-icon-previous{left:0;top:-2394px}.docs-icon-no-color{left:0;top:-2436px}.docs-icon-fill-color{left:0;top:-2226px}.docs-icon-line-color{left:0;top:-2121px}.docs-icon-line-type{left:0;top:-1092px}.docs-icon-table{left:0;top:-2100px}.docs-icon-comment{left:0;top:-3003px}.docs-icon-comment-blank{left:-21px;top:-2163px}.docs-icon-comment-blank-highlighted{left:-21px;top:-693px}.docs-icon-chart{left:0;top:-1743px}.docs-icon-list-number-rtl{left:0;top:-609px}.docs-icon-list-bullet-rtl{left:-21px;top:-1071px}.docs-icon-indent-rtl{left:0;top:-882px}.docs-icon-outdent-rtl{left:-21px;top:-2562px}.docs-icon-line-spacing-rtl{left:0;top:-1785px}.docs-icon-text-ltr{left:0;top:-630px}.docs-icon-text-rtl{left:0;top:-2982px}.docs-icon-sheet-rtl{left:-21px;top:-798px}.docs-icon-share{left:-21px;top:-2709px}.docs-icon-subscript{left:-21px;top:-2205px}.docs-icon-superscript{left:0;top:-2772px}.docs-icon-strikethrough{left:0;top:-2352px}.docs-icon-clear-formatting{left:0;top:-126px}.docs-icon-link{left:0;top:-2688px}.docs-icon-special-character{left:0;top:-2856px}.docs-icon-close-white{left:0;top:-588px}.docs-icon-close-small{left:-21px;top:-2688px}.docs-icon-paint-format{left:-21px;top:-2394px}.docs-icon-video{left:-21px;top:-2499px}.docs-icon-reload{left:0;top:-1617px}.docs-icon-reload-rtl{left:0;top:-147px}.docs-icon-insert-page-break{left:-21px;top:-588px}.docs-icon-close{left:0;top:-2562px}.docs-icon-check{left:-21px;top:-1659px}.docs-icon-up{left:0;top:-1680px}.docs-icon-down{left:0;top:-2667px}.docs-icon-add-page{left:0;top:-21px}.docs-icon-email{left:-21px;top:-1806px}.docs-icon-insert-equation{left:0;top:-672px}.docs-icon-insert-horizontal-line{left:0;top:-1470px}.docs-icon-tabstop-center{left:-21px;top:-2247px}.docs-icon-tabstop-center-bottom{left:0;top:-1407px}.docs-icon-tabstop-left{left:-21px;top:-2835px}.docs-icon-tabstop-right{left:-21px;top:-147px}.docs-icon-border-all{left:-21px;top:-2289px}.docs-icon-border-right{left:0;top:-1491px}.docs-icon-border-left{left:0;top:-1449px}.docs-icon-border-top{left:0;top:-1155px}.docs-icon-border-bottom{left:0;top:-945px}.docs-icon-border-outside{left:-21px;top:-1302px}.docs-icon-border-inside{left:-21px;top:-2940px}.docs-icon-border-none{left:-21px;top:-1386px}.docs-icon-border-horizontal{left:0;top:-2184px}.docs-icon-border-vertical{left:0;top:-2961px}.docs-icon-merge{left:0;top:-1953px}.docs-icon-wrap{left:0;top:-1701px}.docs-icon-autofilter{left:0;top:-399px}.docs-icon-autofilter-filled{left:-21px;top:-2772px}.docs-icon-insert-function{left:0;top:-840px}.docs-icon-insert-formula{left:0;top:0}.docs-icon-folder-shared{left:-21px;top:-2730px}.docs-icon-folder-outline{left:-21px;top:-420px}.docs-icon-folder-outline-hover{left:-21px;top:-2961px}.docs-icon-folder-outline-pressed{left:-21px;top:-2919px}.docs-icon-folder-solid{left:0;top:-252px}.docs-icon-drive{left:0;top:-504px}.docs-icon-drive-grey{left:0;top:-2373px}.docs-icon-drive-grey-hover{left:0;top:-1323px}.docs-icon-drive-grey-pressed{left:-21px;top:-441px}.docs-icon-drive-hover{left:0;top:-987px}.docs-icon-drive-pressed{left:-21px;top:-1974px}.docs-icon-drive-large{left:0;top:-2625px}.docs-icon-back{left:0;top:-2310px}.docs-icon-back-rtl{left:-21px;top:-1701px}.docs-icon-arrow-more{left:0;top:-273px}.docs-icon-arrow-more-rtl{left:0;top:-1575px}.docs-icon-search-this-document{left:0;top:-1596px}.docs-icon-arrow-dropdown{left:0;top:-1428px}.docs-icon-word-art{left:0;top:-336px}.docs-icon-delete-x{left:-21px;top:-1176px}.docs-icon-settings{left:0;top:-1281px}.docs-icon-drive-large-wrapper{width:42px;height:42px}.docs-icon-plus{left:-21px;top:-882px}.docs-icon-plus-white{left:-21px;top:-231px}.docs-icon-alert{left:0;top:-315px}.docs-icon-trash{left:0;top:-462px}.docs-icon-locked{left:0;top:-1806px}.docs-icon-unlocked{left:0;top:-2541px}.docs-icon-add-fonts{left:-21px;top:-2457px}.docs-icon-enter-compact{left:-21px;top:-357px}.docs-icon-exit-compact{left:-21px;top:-315px}.docs-icon-mode-edit{left:-21px;top:0}.docs-icon-mode-review{left:0;top:-1134px}.docs-icon-mode-review-white{left:-21px;top:-1470px}.docs-icon-mode-view{left:0;top:-2940px}.docs-icon-chat{left:-21px;top:-2478px}.docs-icon-star{left:-21px;top:-1869px}.docs-icon-duplicate{left:-21px;top:-1638px}.docs-icon-file{left:0;top:-189px}.docs-icon-opacity{left:-21px;top:-2814px}.docs-icon-label-slant{left:0;top:-798px}.docs-icon-point-size{left:0;top:-294px}.docs-icon-question{left:0;top:-651px}.docs-icon-vertical-gridlines{left:-21px;top:-630px}.docs-icon-left-axis{left:-21px;top:-2520px}.docs-icon-right-axis{left:0;top:-357px}.docs-icon-left-axis-gridlines{left:0;top:-2499px}.docs-icon-right-axis-gridlines{left:0;top:-3045px}.docs-icon-reset{left:0;top:-693px}.docs-icon-drag-move{left:0;top:-1638px}.docs-icon-col-dragger{left:-21px;top:-1764px}.docs-icon-chrome-store{left:0;top:-2016px}.docs-icon-fit-area{left:-21px;top:-273px}.docs-icon-zoom-out{left:0;top:-1974px}.docs-icon-zoom-tool{left:0;top:-546px}.docs-icon-download{left:0;top:-2730px}.docs-icon-fusion-table{left:0;top:-2163px}.docs-icon-spreadsheet-sink{left:-21px;top:-2079px}.docs-icon-send-responses{left:0;top:-2205px}.docs-icon-liveform{left:-21px;top:-1743px}.docs-icon-ellipsis{left:0;top:-819px}.docs-icon-html-preview{left:0;top:-2919px}.docs-icon-grid{left:0;top:-1365px}.docs-icon-add-animation{left:0;top:-420px}.docs-icon-playhead{left:0;top:-2247px}.docs-icon-playhead-rtl{left:0;top:-1302px}.docs-icon-unsupported{left:-21px;top:-3024px}.docs-icon-calendar{left:0;top:-2751px}.docs-zippy-closed{left:0;top:-1008px}.docs-zippy-open{left:-21px;top:-1407px}.docs-icon-bookmark{left:0;top:-1050px}.docs-icon-heading{left:0;top:-2898px}.docs-icon-file-blue{left:0;top:-1218px}.docs-icon-web-result{left:-21px;top:-1449px}.docs-icon-mic{left:-21px;top:-987px}.docs-icon-paragraph{left:-21px;top:-1785px}.docs-icon-bookmark-black{left:-21px;top:-2793px}.docs-icon-web-result-blue{left:-21px;top:-168px}.docs-icon-popout{left:-21px;top:-651px}.docs-icon-checkbox-type{left:0;top:-1176px}.docs-icon-dropdown-type{left:-21px;top:-1995px}.docs-icon-grid-type{left:-21px;top:-2898px}.docs-icon-image-type{left:0;top:-2457px}.docs-icon-radio-type{left:0;top:-483px}.docs-icon-scale-type{left:-21px;top:-2037px}.docs-icon-text-type{left:-21px;top:-1554px}.docs-icon-time-type{left:-21px;top:-819px}.docs-icon-insert-text-block{left:-21px;top:-2016px}.docs-icon-accepting-responses-on{left:-21px;top:-672px}.docs-icon-accepting-responses-off{left:0;top:-2268px}.docs-icon-decimal-increase{left:-21px;top:-756px}.docs-icon-decimal-decrease{left:-21px;top:-1260px}.docs-icon-settings-white{left:0;top:-1869px}.docs-icon-no-symbol{left:-21px;top:-462px}.docs-icon-crop{left:-21px;top:-2100px}.docs-icon-green-check{left:-21px;top:-1008px}}#googlebar-coldstart{height:28px;line-height:28px;background-color:transparent;padding:0 30px;z-index:1001}.googlebar-coldstart-email-container{background-color:#fff;float:right;height:inherit}.googlebar-coldstart-email{color:#999;font:Arial,sans-serif;font-size:11px;padding:0 15px}.modal-dialog a{color:#15c}.gview-html-content{border:1px #dadada solid;color:black;font-family:monospace;margin:24px 30px 24px 38px;padding:25px}
</style><style type="text/css"><!--
    /* Pretty printing styles. Used with prettify.js. */

/* SPAN elements with the classes below are added by prettyprint. */
.str { color: #080; }
.kwd { color: #008; }
.com { color: #800; }
.typ { color: #606; }
.lit { color: #066; }
.pun, .opn, .clo { color: #660; }
.pln { color: #000; }
.tag { color: #008; }
.atn { color: #606; }
.atv { color: #080; }
.dec { color: #606; }

/* Use higher contrast and font-styling for printable form. */
@media print {
  .str { color: #060; }
  .kwd { color: #006; font-weight: bold; }
  .com { color: #600; font-style: italic; }
  .typ { color: #404; font-weight: bold; }
  .lit { color: #044; }
  .pun, .opn, .clo { color: #440; }
  .pln { color: #000; }
  .tag { color: #006; font-weight: bold; }
  .atn { color: #404; }
  .atv { color: #060; }
}

/* Put a border around prettyprinted code snippets. */
pre.prettyprint { padding: 2px; border: 1px solid #888 }

/* Specify class=linenums on a pre to get line numbering */
ol.linenums { margin-top: 0; margin-bottom: 0 } /* IE indents via margin-left */
li.L0,
li.L1,
li.L2,
li.L3,
li.L5,
li.L6,
li.L7,
li.L8 { list-style-type: none }
/* Alternate shading for lines */
li.L1,
li.L3,
li.L5,
li.L7,
li.L9 { background: #eee }

    pre.prettyprint { padding: 10px; border: none }
--></style><style type="text/css">
    
    .gview-html-content,
    .gview-container-content {
      background-color: #FFF;
      
      
        text-align: left;
      
    }

    .gview-container-content {
      width: 100%;
    }
  </style></head>
<body class="goog-useragent-webkit "><noscript>&lt;div&gt;Your browser must support javascript.&lt;/div&gt;
</noscript>

<div id="gview"><div class="view" id="view"><textarea id="selection-content" cols="1" rows="1" readonly="" tabindex="-1"></textarea>
<div class="goog-inline-block goog-toolbar" id="controlbar"><div id="buttonElements"><div id="prevToolbarButton" class="goog-inline-block goog-toolbar-button" role="button" style="-webkit-user-select: none;" aria-disabled="false" data-tooltip="Ver página anterior (←)" aria-label="Ver página anterior (←)" tabindex="0"><div class="goog-inline-block goog-toolbar-button-outer-box"><div class="goog-inline-block goog-toolbar-button-inner-box"><div id="prevToolbarButtonIcon" class="toolbar-button-icon           docs-icon"></div></div></div></div><div id="nextToolbarButton" class="goog-inline-block goog-toolbar-button" role="button" style="-webkit-user-select: none;" aria-disabled="false" data-tooltip="Ver página siguiente (→)" aria-label="Ver página siguiente (→)" tabindex="0"><div class="goog-inline-block goog-toolbar-button-outer-box"><div class="goog-inline-block goog-toolbar-button-inner-box"><div id="nextToolbarButtonIcon" class="toolbar-button-icon           docs-icon"></div></div></div></div><div class="goog-inline-block separator" id="separator1"></div><div id="printToolbarButton" class="goog-inline-block goog-toolbar-button goog-toolbar-button-disabled" role="button" style="-webkit-user-select: none; display: none;" aria-disabled="true" data-tooltip="Imprimir (PDF) (Ctrl+P)" aria-label="Imprimir (PDF) (Ctrl+P)" aria-hidden="true"><div class="goog-inline-block goog-toolbar-button-outer-box"><div class="goog-inline-block goog-toolbar-button-inner-box"><div id="printToolbarButtonIcon" class="toolbar-button-icon                docs-icon"></div></div></div></div><div class="goog-inline-block separator" id="separator2"></div><div id="zoomOutToolbarButton" class="goog-inline-block goog-toolbar-button" tabindex="0" role="button" style="-webkit-user-select: none;" data-tooltip="Reducir (Ctrl+Shift+←)" aria-label="Reducir (Ctrl+Shift+←)"><div class="goog-inline-block goog-toolbar-button-outer-box"><div class="goog-inline-block goog-toolbar-button-inner-box"><div id="zoomOutToolbarButtonIcon" class="toolbar-button-icon           docs-icon"></div></div></div></div><div id="zoomInToolbarButton" class="goog-inline-block goog-toolbar-button" tabindex="0" role="button" style="-webkit-user-select: none;" data-tooltip="Ampliar (Ctrl+Shift+→)" aria-label="Ampliar (Ctrl+Shift+→)"><div class="goog-inline-block goog-toolbar-button-outer-box"><div class="goog-inline-block goog-toolbar-button-inner-box"><div id="zoomInToolbarButtonIcon" class="toolbar-button-icon           docs-icon"></div></div></div></div></div><div id="searchElements" class="goog-inline-block" style="display: none;"><div class="goog-inline-block search-message goog-inline-follow-pad" id="toolbarSearchMessage" style="display: none;"></div><div class="goog-inline-block"><div id="searchIcon" class="goog-inline-block toolbar-button-icon            goog-toolbar-button-disabled"></div><input id="searchBox" class="goog-inline-block search-box" disabled="" type="text" autocomplete="off" tabindex="0" value="Loading..."><div id="prevSearchToolbarButton" class="goog-inline-block toolbar-button-icon docs-icon goog-control goog-control-disabled" style="-webkit-user-select: none; display: none;" aria-disabled="true" data-tooltip="Busca el resultado anterior" aria-label="Busca el resultado anterior" aria-hidden="true"></div><div id="nextSearchToolbarButton" class="goog-inline-block toolbar-button-icon docs-icon goog-control goog-control-disabled" style="-webkit-user-select: none; display: none;" aria-disabled="true" data-tooltip="Busca el resultado siguiente" aria-label="Busca el resultado siguiente" aria-hidden="true"></div></div></div><div id="clearer" style="clear: both;"></div></div>
<div class="thumb-pane" id="thumb-pane" style="display: none;"><div class="thumb-pane-toggle goog-inline-block goog-toolbar-button thumb-pane-show" id="thumb-pane-toggle" role="button" style="-webkit-user-select: none;" tabindex="0"><div class="goog-inline-block goog-toolbar-button-outer-box"><div class="goog-inline-block goog-toolbar-button-inner-box"></div></div></div>
<div class="thumb-pane-upper" id="thumb-pane-upper"></div>
<div id="thumb-pane-lower" class="thumb-pane-lower gview-scrollbar jfk-scrollbar"><div class="thumb-elements"></div></div></div>
<div id="content-pane" class="gview-scrollbar jfk-scrollbar" tabindex="0" style="top: 37px; left: 0px; width: 1307px; height: 526px;"><div id="page-pane" class="noselect"><div id="gview-html-content" class="goog-inline-block gview-html-content">

<div>
    <script type="text/javascript">//<![CDATA[
  function do_pretty_print() {
    (function() {
/*
 Copyright (C) 2006 Google Inc.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
window.PR_SHOULD_USE_CONTINUATION=!0;window.PR_TAB_WIDTH=8;window.PR_normalizedHtml=void 0;window.PR=void 0;window.prettyPrintOne=void 0;window.prettyPrint=void 0;window._pr_isIE6=function(){var y=navigator&&navigator.userAgent&&navigator.userAgent.match(/\bMSIE ([678])\./),y=y?+y[1]:!1;window._pr_isIE6=function(){return y};return y};
(function(){function y(a){return a.replace(F,"&amp;").replace(G,"&lt;").replace(H,"&gt;")}function C(a,b,m){switch(a.nodeType){case 1:var n=a.tagName.toLowerCase();b.push("<",n);var h=a.attributes,r=h.length;if(r){if(m){for(var v=[],f=r;0<=--f;)v[f]=h[f];v.sort(function(a,b){return a.name<b.name?-1:a.name===b.name?0:1});h=v}for(f=0;f<r;++f)v=h[f],v.specified&&b.push(" ",v.name.toLowerCase(),'="',v.value.replace(F,"&amp;").replace(G,"&lt;").replace(H,"&gt;").replace(N,"&quot;"),'"')}b.push(">");for(h=
a.firstChild;h;h=h.nextSibling)C(h,b,m);!a.firstChild&&/^(?:br|link|img)$/.test(n)||b.push("</",n,">");break;case 3:case 4:b.push(y(a.nodeValue))}}function I(a){function b(a){if("\\"!==a.charAt(0))return a.charCodeAt(0);switch(a.charAt(1)){case "b":return 8;case "t":return 9;case "n":return 10;case "v":return 11;case "f":return 12;case "r":return 13;case "u":case "x":return parseInt(a.substring(2),16)||a.charCodeAt(1);case "0":case "1":case "2":case "3":case "4":case "5":case "6":case "7":return parseInt(a.substring(1),
8);default:return a.charCodeAt(1)}}function m(a){if(32>a)return(16>a?"\\x0":"\\x")+a.toString(16);a=String.fromCharCode(a);if("\\"===a||"-"===a||"["===a||"]"===a)a="\\"+a;return a}function n(a){var l=a.substring(1,a.length-1).match(RegExp("\\\\u[0-9A-Fa-f]{4}|\\\\x[0-9A-Fa-f]{2}|\\\\[0-3][0-7]{0,2}|\\\\[0-7]{1,2}|\\\\[\\s\\S]|-|[^-\\\\]","g"));a=[];for(var c=[],f="^"===l[0],e=f?1:0,p=l.length;e<p;++e){var k=l[e];switch(k){case "\\B":case "\\b":case "\\D":case "\\d":case "\\S":case "\\s":case "\\W":case "\\w":a.push(k);
continue}var k=b(k),d;e+2<p&&"-"===l[e+1]?(d=b(l[e+2]),e+=2):d=k;c.push([k,d]);65>d||122<k||(65>d||90<k||c.push([Math.max(65,k)|32,Math.min(d,90)|32]),97>d||122<k||c.push([Math.max(97,k)&-33,Math.min(d,122)&-33]))}c.sort(function(a,c){return a[0]-c[0]||c[1]-a[1]});l=[];k=[NaN,NaN];for(e=0;e<c.length;++e)p=c[e],p[0]<=k[1]+1?k[1]=Math.max(k[1],p[1]):l.push(k=p);c=["["];f&&c.push("^");c.push.apply(c,a);for(e=0;e<l.length;++e)p=l[e],c.push(m(p[0])),p[1]>p[0]&&(p[1]+1>p[0]&&c.push("-"),c.push(m(p[1])));
c.push("]");return c.join("")}function h(a){for(var b=a.source.match(RegExp("(?:\\[(?:[^\\x5C\\x5D]|\\\\[\\s\\S])*\\]|\\\\u[A-Fa-f0-9]{4}|\\\\x[A-Fa-f0-9]{2}|\\\\[0-9]+|\\\\[^ux0-9]|\\(\\?[:!=]|[\\(\\)\\^]|[^\\x5B\\x5C\\(\\)\\^]+)","g")),c=b.length,d=[],e=0,f=0;e<c;++e){var k=b[e];"("===k?++f:"\\"===k.charAt(0)&&(k=+k.substring(1))&&k<=f&&(d[k]=-1)}for(e=1;e<d.length;++e)-1===d[e]&&(d[e]=++r);for(f=e=0;e<c;++e)k=b[e],"("===k?(++f,void 0===d[f]&&(b[e]="(?:")):"\\"===k.charAt(0)&&(k=+k.substring(1))&&
k<=f&&(b[e]="\\"+d[f]);for(f=e=0;e<c;++e)"^"===b[e]&&"^"!==b[e+1]&&(b[e]="");if(a.ignoreCase&&v)for(e=0;e<c;++e)k=b[e],a=k.charAt(0),2<=k.length&&"["===a?b[e]=n(k):"\\"!==a&&(b[e]=k.replace(/[a-zA-Z]/g,function(a){a=a.charCodeAt(0);return"["+String.fromCharCode(a&-33,a|32)+"]"}));return b.join("")}for(var r=0,v=!1,f=!1,t=0,d=a.length;t<d;++t){var w=a[t];if(w.ignoreCase)f=!0;else if(/[a-z]/i.test(w.source.replace(/\\u[0-9a-f]{4}|\\x[0-9a-f]{2}|\\[^ux]/gi,""))){v=!0;f=!1;break}}for(var s=[],t=0,d=a.length;t<
d;++t){w=a[t];if(w.global||w.multiline)throw Error(""+w);s.push("(?:"+h(w)+")")}return new RegExp(s.join("|"),f?"gi":"g")}function O(a){var b=0;return function(m){for(var n=null,h=0,r=0,v=m.length;r<v;++r){var f=m.charAt(r);switch(f){case "\t":n||(n=[]);n.push(m.substring(h,r));h=a-b%a;for(b+=h;0<=h;h-=16)n.push("                ".substring(0,h));h=r+1;break;case "\n":b=0;break;default:++b}}if(!n)return m;n.push(m.substring(h));return n.join("")}}function D(a,b,m,n){b&&(a={source:b,basePos:a},m(a),
n.push.apply(n,a.decorations))}function z(a,b){var m={},n;(function(){for(var h=a.concat(b),f=[],r={},d=0,w=h.length;d<w;++d){var s=h[d],u=s[3];if(u)for(var l=u.length;0<=--l;)m[u.charAt(l)]=s;s=s[1];u=""+s;r.hasOwnProperty(u)||(f.push(s),r[u]=null)}f.push(/[\0-\uffff]/);n=I(f)})();var h=b.length,r=function(a){for(var f=a.source,t=a.basePos,d=[t,"pln"],w=0,f=f.match(n)||[],s={},u=0,l=f.length;u<l;++u){var c=f[u],q=s[c],e=void 0,p;if("string"===typeof q)p=!1;else{var k=m[c.charAt(0)];if(k)e=c.match(k[1]),
q=k[0];else{for(p=0;p<h;++p)if(k=b[p],e=c.match(k[1])){q=k[0];break}e||(q="pln")}!(p=5<=q.length&&"lang-"===q.substring(0,5))||e&&"string"===typeof e[1]||(p=!1,q="src");p||(s[c]=q)}k=w;w+=c.length;if(p){p=e[1];var A=c.indexOf(p),g=A+p.length;e[2]&&(g=c.length-e[2].length,A=g-p.length);q=q.substring(5);D(t+k,c.substring(0,A),r,d);D(t+k+A,p,K(q,p),d);D(t+k+g,c.substring(g),r,d)}else d.push(t+k,q)}a.decorations=d};return r}function x(a){var b=[],m=[];a.tripleQuotedStrings?b.push(["str",/^(?:\'\'\'(?:[^\'\\]|\\[\s\S]|\'{1,2}(?=[^\']))*(?:\'\'\'|$)|\"\"\"(?:[^\"\\]|\\[\s\S]|\"{1,2}(?=[^\"]))*(?:\"\"\"|$)|\'(?:[^\\\']|\\[\s\S])*(?:\'|$)|\"(?:[^\\\"]|\\[\s\S])*(?:\"|$))/,
null,"'\""]):a.multiLineStrings?b.push(["str",/^(?:\'(?:[^\\\']|\\[\s\S])*(?:\'|$)|\"(?:[^\\\"]|\\[\s\S])*(?:\"|$)|\`(?:[^\\\`]|\\[\s\S])*(?:\`|$))/,null,"'\"`"]):b.push(["str",/^(?:\'(?:[^\\\'\r\n]|\\.)*(?:\'|$)|\"(?:[^\\\"\r\n]|\\.)*(?:\"|$))/,null,"\"'"]);a.verbatimStrings&&m.push(["str",/^@\"(?:[^\"]|\"\")*(?:\"|$)/,null]);var n=a.hashComments;n&&(a.cStyleComments?(1<n?b.push(["com",/^#(?:##(?:[^#]|#(?!##))*(?:###|$)|.*)/,null,"#"]):b.push(["com",/^#(?:(?:define|elif|else|endif|error|ifdef|include|ifndef|line|pragma|undef|warning)\b|[^\r\n]*)/,
null,"#"]),m.push(["str",/^<(?:(?:(?:\.\.\/)*|\/?)(?:[\w-]+(?:\/[\w-]+)+)?[\w-]+\.h|[a-z]\w*)>/,null])):b.push(["com",/^#[^\r\n]*/,null,"#"]));a.cStyleComments&&(m.push(["com",/^\/\/[^\r\n]*/,null]),m.push(["com",/^\/\*[\s\S]*?(?:\*\/|$)/,null]));a.regexLiterals&&m.push(["lang-regex",new RegExp("^"+P+"(/(?=[^/*])(?:[^/\\x5B\\x5C]|\\x5C[\\s\\S]|\\x5B(?:[^\\x5C\\x5D]|\\x5C[\\s\\S])*(?:\\x5D|$))+/)")]);a=a.keywords.replace(/^\s+|\s+$/g,"");a.length&&m.push(["kwd",new RegExp("^(?:"+a.replace(/\s+/g,"|")+
")\\b"),null]);b.push(["pln",/^\s+/,null," \r\n\t\u00a0"]);m.push(["lit",/^@[a-z_$][a-z_$@0-9]*/i,null],["typ",/^@?[A-Z]+[a-z][A-Za-z_$@0-9]*/,null],["pln",/^[a-z_$][a-z_$@0-9]*/i,null],["lit",/^(?:0x[a-f0-9]+|(?:\d(?:_\d+)*\d*(?:\.\d*)?|\.\d\+)(?:e[+\-]?\d+)?)[a-z]*/i,null,"0123456789"],["pun",/^.[^\s\w\.$@\'\"\`\/\#]*/,null]);return z(b,m)}function Q(a){function b(a){if(a>t){d&&d!==w&&(f.push("</span>"),d=null);!d&&w&&(d=w,f.push('<span class="',d,'">'));var b=y(l(m.substring(t,a))).replace(k?q:
c,"$1&#160;");k=p.test(b);f.push(b.replace(e,x));t=a}}var m=a.source,n=a.extractedTags,h=a.decorations,r=a.numberLines,v=a.sourceNode,f=[],t=0,d=null,w=null,s=0,u=0,l=O(window.PR_TAB_WIDTH),c=/([\r\n ]) /g,q=/(^| ) /gm,e=/\r\n?|\n/g,p=/[ \r\n]$/,k=!0,g=window._pr_isIE6(),v=g?v&&"PRE"===v.tagName?6===g?"&#160;\r\n":7===g?"&#160;<br />\r":8===g?"&#160;<br />":"&#160;\r":"&#160;<br />":"<br />",x;if(r){for(var J=[],g=0;10>g;++g)J[g]=v+'</li><li class="L'+g+'">';var z="number"===typeof r?r-1:0;f.push('<ol class="linenums"><li class="L',
z%10,'"');z&&f.push(' value="',z+1,'"');f.push(">");x=function(){var a=J[++z%10];return d?"</span>"+a+'<span class="'+d+'">':a}}else x=v;for(;;)if(v=s<n.length?u<h.length?n[s]<=h[u]:!0:!1)b(n[s]),d&&(f.push("</span>"),d=null),f.push(n[s+1]),s+=2;else if(u<h.length)b(h[u]),w=h[u+1],u+=2;else break;b(m.length);d&&f.push("</span>");r&&f.push("</li></ol>");a.prettyPrintedHtml=f.join("")}function g(a,b){for(var m=b.length;0<=--m;){var n=b[m];B.hasOwnProperty(n)?"console"in window&&console.warn("cannot override language handler %s",
n):B[n]=a}}function K(a,b){a&&B.hasOwnProperty(a)||(a=/^\s*</.test(b)?"default-markup":"default-code");return B[a]}function L(a){var b=a.sourceCodeHtml,m=a.langExtension;a.prettyPrintedHtml=b;try{var n,h=b.match(R),b=[],r=0,g=[];if(h)for(var f=0,t=h.length;f<t;++f){var d=h[f];if(1<d.length&&"<"===d.charAt(0)){if(!S.test(d))if(T.test(d))b.push(d.substring(9,d.length-3)),r+=d.length-12;else if(U.test(d))b.push("\n"),++r;else if(0<=d.indexOf("nocode")&&d.replace(/\s(\w+)\s*=\s*(?:\"([^\"]*)\"|'([^\']*)'|(\S+))/g,
' $1="$2$3$4"').match(/[cC][lL][aA][sS][sS]=\"[^\"]*\bnocode\b/)){var w=d.match(M)[2],s=1,u;u=f+1;e:for(;u<t;++u){var l=h[u].match(M);if(l&&l[2]===w)if("/"===l[1]){if(0===--s)break e}else++s}u<t?(g.push(r,h.slice(f,u+1).join("")),f=u):g.push(r,d)}else g.push(r,d)}else{var c;var s=d,q=s.indexOf("&");if(0>q)c=s;else{for(--q;0<=(q=s.indexOf("&#",q+1));){var e=s.indexOf(";",q);if(0<=e){var p=s.substring(q+3,e),k=10;p&&"x"===p.charAt(0)&&(p=p.substring(1),k=16);var x=parseInt(p,k);isNaN(x)||(s=s.substring(0,
q)+String.fromCharCode(x)+s.substring(e+1))}}c=s.replace(V,"<").replace(W,">").replace(X,"'").replace(Y,'"').replace(Z," ").replace($,"&")}b.push(c);r+=c.length}}n={source:b.join(""),tags:g};var z=n.source;a.source=z;a.basePos=0;a.extractedTags=n.tags;K(m,z)(a);Q(a)}catch(y){"console"in window&&console.log(y&&y.stack?y.stack:y)}}function aa(a,b,m){a={sourceCodeHtml:a,langExtension:b,numberLines:m};L(a);return a.prettyPrintedHtml}function ba(a){function b(){for(var m=window.PR_SHOULD_USE_CONTINUATION?
f.now()+250:Infinity;t<n.length&&f.now()<m;t++){var h=n[t];if(h.className&&0<=h.className.indexOf("prettyprint")){var g=h.className.match(/\blang-(\w+)\b/);g&&(g=g[1]);for(var l=!1,c=h.parentNode;c;c=c.parentNode)if(("pre"===c.tagName||"code"===c.tagName||"xmp"===c.tagName)&&c.className&&0<=c.className.indexOf("prettyprint")){l=!0;break}if(!l){c=h;null===E&&(l=document.createElement("PRE"),l.appendChild(document.createTextNode('<!DOCTYPE foo PUBLIC "foo bar">\n<foo />')),E=!/</.test(l.innerHTML));
if(E)if(l=c.innerHTML,"XMP"===c.tagName)l=y(l);else{if("PRE"!==c.tagName&&ca.test(l)){var q="";c.currentStyle?q=c.currentStyle.whiteSpace:window.getComputedStyle&&(q=window.getComputedStyle(c,null).whiteSpace);c=!q||"pre"===q}else c=!0;c||(l=l.replace(/(<br\s*\/?>)[\r\n]+/g,"$1").replace(/(?:[\r\n]+[ \t]*)+/g," "))}else{l=[];for(c=c.firstChild;c;c=c.nextSibling)C(c,l);l=l.join("")}l=l.replace(/(?:\r\n?|\n)$/,"");c=h.className.match(/\blinenums\b(?::(\d+))?/);d={sourceCodeHtml:l,langExtension:g,sourceNode:h,
numberLines:c?c[1]&&c[1].length?+c[1]:!0:!1};L(d);if(h=d.prettyPrintedHtml)if(g=d.sourceNode,"XMP"===g.tagName){l=document.createElement("PRE");for(c=0;c<g.attributes.length;++c)if(q=g.attributes[c],q.specified){var e=q.name.toLowerCase();"class"===e?l.className=q.value:l.setAttribute(q.name,q.value)}l.innerHTML=h;g.parentNode.replaceChild(l,g)}else g.innerHTML=h}}}t<n.length?setTimeout(b,250):a&&a()}for(var m=[document.getElementsByTagName("pre"),document.getElementsByTagName("code"),document.getElementsByTagName("xmp")],
n=[],h=0;h<m.length;++h)for(var g=0,v=m[h].length;g<v;++g)n.push(m[h][g]);var m=null,f=Date;f.now||(f={now:function(){return(new Date).getTime()}});var t=0,d;b()}var P=function(){for(var a="! != !== # % %= & && &&= &= ( * *= += , -= -> / /= : :: ; < << <<= <= = == === > >= >> >>= >>> >>>= ? @ [ ^ ^= ^^ ^^= { | |= || ||= ~ break case continue delete do else finally instanceof return throw try typeof".split(" "),b="(?:^^|[+-]",g=0;g<a.length;++g)b+="|"+a[g].replace(/([^=<>:&a-z])/g,"\\$1");return b+=
")\\s*"}(),F=/&/g,G=/</g,H=/>/g,N=/\"/g,V=/&lt;/g,W=/&gt;/g,X=/&apos;/g,Y=/&quot;/g,$=/&amp;/g,Z=/&nbsp;/g,ca=/[\r\n]/g,E=null,R=RegExp("[^<]+|\x3c!--[\\s\\S]*?--\x3e|<!\\[CDATA\\[[\\s\\S]*?\\]\\]>|</?[a-zA-Z](?:[^>\"']|'[^']*'|\"[^\"]*\")*>|<","g"),S=/^<\!--/,T=/^<!\[CDATA\[/,U=/^<br\b/i,M=/^<(\/?)([a-zA-Z][a-zA-Z0-9]*)/,da=x({keywords:"break continue do else for if return while auto case char const default double enum extern float goto int long register short signed sizeof static struct switch typedef union unsigned void volatile catch class delete false import new operator private protected public this throw true try typeof alignof align_union asm axiom bool concept concept_map const_cast constexpr decltype dynamic_cast explicit export friend inline late_check mutable namespace nullptr reinterpret_cast static_assert static_cast template typeid typename using virtual wchar_t where break continue do else for if return while auto case char const default double enum extern float goto int long register short signed sizeof static struct switch typedef union unsigned void volatile catch class delete false import new operator private protected public this throw true try typeof abstract boolean byte extends final finally implements import instanceof null native package strictfp super synchronized throws transient as base by checked decimal delegate descending dynamic event fixed foreach from group implicit in interface internal into is lock object out override orderby params partial readonly ref sbyte sealed stackalloc string select uint ulong unchecked unsafe ushort var break continue do else for if return while auto case char const default double enum extern float goto int long register short signed sizeof static struct switch typedef union unsigned void volatile catch class delete false import new operator private protected public this throw true try typeof debugger eval export function get null set undefined var with Infinity NaN caller delete die do dump elsif eval exit foreach for goto if import last local my next no our print package redo require sub undef unless until use wantarray while BEGIN END break continue do else for if return while and as assert class def del elif except exec finally from global import in is lambda nonlocal not or pass print raise try with yield False True None break continue do else for if return while alias and begin case class def defined elsif end ensure false in module next nil not or redo rescue retry self super then true undef unless until when yield BEGIN END break continue do else for if return while case done elif esac eval fi function in local set then until ",
hashComments:!0,cStyleComments:!0,multiLineStrings:!0,regexLiterals:!0}),B={};g(da,["default-code"]);g(z([],[["pln",/^[^<?]+/],["dec",/^<!\w[^>]*(?:>|$)/],["com",/^<\!--[\s\S]*?(?:-\->|$)/],["lang-",/^<\?([\s\S]+?)(?:\?>|$)/],["lang-",/^<%([\s\S]+?)(?:%>|$)/],["pun",/^(?:<[%?]|[%?]>)/],["lang-",/^<xmp\b[^>]*>([\s\S]+?)<\/xmp\b[^>]*>/i],["lang-js",/^<script\b[^>]*>([\s\S]*?)(<\/script\b[^>]*>)/i],["lang-css",/^<style\b[^>]*>([\s\S]*?)(<\/style\b[^>]*>)/i],["lang-in.tag",/^(<\/?[a-z][^<>]*>)/i]]),"default-markup htm html mxml xhtml xml xsl".split(" "));
g(z([["pln",/^[\s]+/,null," \t\r\n"],["atv",/^(?:\"[^\"]*\"?|\'[^\']*\'?)/,null,"\"'"]],[["tag",/^^<\/?[a-z](?:[\w.:-]*\w)?|\/?>$/i],["atn",/^(?!style[\s=]|on)[a-z](?:[\w:-]*\w)?/i],["lang-uq.val",/^=\s*([^>\'\"\s]*(?:[^>\'\"\s\/]|\/(?=\s)))/],["pun",/^[=<>\/]+/],["lang-js",/^on\w+\s*=\s*\"([^\"]+)\"/i],["lang-js",/^on\w+\s*=\s*\'([^\']+)\'/i],["lang-js",/^on\w+\s*=\s*([^\"\'>\s]+)/i],["lang-css",/^style\s*=\s*\"([^\"]+)\"/i],["lang-css",/^style\s*=\s*\'([^\']+)\'/i],["lang-css",/^style\s*=\s*([^\"\'>\s]+)/i]]),
["in.tag"]);g(z([],[["atv",/^[\s\S]+/]]),["uq.val"]);g(x({keywords:"break continue do else for if return while auto case char const default double enum extern float goto int long register short signed sizeof static struct switch typedef union unsigned void volatile catch class delete false import new operator private protected public this throw true try typeof alignof align_union asm axiom bool concept concept_map const_cast constexpr decltype dynamic_cast explicit export friend inline late_check mutable namespace nullptr reinterpret_cast static_assert static_cast template typeid typename using virtual wchar_t where ",
hashComments:!0,cStyleComments:!0}),"c cc cpp cxx cyc m".split(" "));g(x({keywords:"null true false"}),["json"]);g(x({keywords:"break continue do else for if return while auto case char const default double enum extern float goto int long register short signed sizeof static struct switch typedef union unsigned void volatile catch class delete false import new operator private protected public this throw true try typeof abstract boolean byte extends final finally implements import instanceof null native package strictfp super synchronized throws transient as base by checked decimal delegate descending dynamic event fixed foreach from group implicit in interface internal into is lock object out override orderby params partial readonly ref sbyte sealed stackalloc string select uint ulong unchecked unsafe ushort var ",
hashComments:!0,cStyleComments:!0,verbatimStrings:!0}),["cs"]);g(x({keywords:"break continue do else for if return while auto case char const default double enum extern float goto int long register short signed sizeof static struct switch typedef union unsigned void volatile catch class delete false import new operator private protected public this throw true try typeof abstract boolean byte extends final finally implements import instanceof null native package strictfp super synchronized throws transient ",
cStyleComments:!0}),["java"]);g(x({keywords:"break continue do else for if return while case done elif esac eval fi function in local set then until ",hashComments:!0,multiLineStrings:!0}),["bsh","csh","sh"]);g(x({keywords:"break continue do else for if return while and as assert class def del elif except exec finally from global import in is lambda nonlocal not or pass print raise try with yield False True None ",hashComments:!0,multiLineStrings:!0,tripleQuotedStrings:!0}),["cv","py"]);g(x({keywords:"caller delete die do dump elsif eval exit foreach for goto if import last local my next no our print package redo require sub undef unless until use wantarray while BEGIN END ",
hashComments:!0,multiLineStrings:!0,regexLiterals:!0}),["perl","pl","pm"]);g(x({keywords:"break continue do else for if return while alias and begin case class def defined elsif end ensure false in module next nil not or redo rescue retry self super then true undef unless until when yield BEGIN END ",hashComments:!0,multiLineStrings:!0,regexLiterals:!0}),["rb"]);g(x({keywords:"break continue do else for if return while auto case char const default double enum extern float goto int long register short signed sizeof static struct switch typedef union unsigned void volatile catch class delete false import new operator private protected public this throw true try typeof debugger eval export function get null set undefined var with Infinity NaN ",
cStyleComments:!0,regexLiterals:!0}),["js"]);g(x({keywords:"all and by catch class else extends false finally for if in is isnt loop new no not null of off on or return super then true try unless until when while yes ",hashComments:3,cStyleComments:!0,multilineStrings:!0,tripleQuotedStrings:!0,regexLiterals:!0}),["coffee"]);g(z([],[["str",/^[\s\S]+/]]),["regex"]);window.PR_normalizedHtml=C;window.prettyPrintOne=aa;window.prettyPrint=ba;window.PR={combinePrefixPatterns:I,createSimpleLexer:z,registerLangHandler:g,
sourceDecorator:x,PR_ATTRIB_NAME:"atn",PR_ATTRIB_VALUE:"atv",PR_COMMENT:"com",PR_DECLARATION:"dec",PR_KEYWORD:"kwd",PR_LITERAL:"lit",PR_NOCODE:"nocode",PR_PLAIN:"pln",PR_PUNCTUATION:"pun",PR_SOURCE:"src",PR_STRING:"str",PR_TAG:"tag",PR_TYPE:"typ"}})();/*
 Copyright (C) 2009 Onno Hommes.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
PR.registerLangHandler(PR.createSimpleLexer([[PR.PR_COMMENT,/^#[^\r\n]*/,null,"#"],[PR.PR_PLAIN,/^[\t\n\r \xA0]+/,null,"\t\n\r \u00a0"],[PR.PR_STRING,/^\"(?:[^\"\\]|\\[\s\S])*(?:\"|$)/,null,'"']],[[PR.PR_KEYWORD,/^(?:ADS|AD|AUG|BZF|BZMF|CAE|CAF|CA|CCS|COM|CS|DAS|DCA|DCOM|DCS|DDOUBL|DIM|DOUBLE|DTCB|DTCF|DV|DXCH|EDRUPT|EXTEND|INCR|INDEX|NDX|INHINT|LXCH|MASK|MSK|MP|MSU|NOOP|OVSK|QXCH|RAND|READ|RELINT|RESUME|RETURN|ROR|RXOR|SQUARE|SU|TCR|TCAA|OVSK|TCF|TC|TS|WAND|WOR|WRITE|XCH|XLQ|XXALQ|ZL|ZQ|ADD|ADZ|SUB|SUZ|MPY|MPR|MPZ|DVP|COM|ABS|CLA|CLZ|LDQ|STO|STQ|ALS|LLS|LRS|TRA|TSQ|TMI|TOV|AXT|TIX|DLY|INP|OUT)\s/,
null],[PR.PR_TYPE,/^(?:-?GENADR|=MINUS|2BCADR|VN|BOF|MM|-?2CADR|-?[1-6]DNADR|ADRES|BBCON|[SE]?BANK\=?|BLOCK|BNKSUM|E?CADR|COUNT\*?|2?DEC\*?|-?DNCHAN|-?DNPTR|EQUALS|ERASE|MEMORY|2?OCT|REMADR|SETLOC|SUBRO|ORG|BSS|BES|SYN|EQU|DEFINE|END)\s/,null],[PR.PR_LITERAL,/^\'(?:-*(?:\w|\\[\x21-\x7e])(?:[\w-]*|\\[\x21-\x7e])[=!?]?)?/],[PR.PR_PLAIN,/^-*(?:[!-z_]|\\[\x21-\x7e])(?:[\w-]*|\\[\x21-\x7e])[=!?]?/i],[PR.PR_PUNCTUATION,/^[^\w\t\n\r \xA0()\"\\\';]+/]]),["apollo","agc","aea"]);/*
 Copyright (C) 2011 Google Inc.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
PR.registerLangHandler(PR.createSimpleLexer([["opn",/^[\(\{\[]+/,null,"([{"],["clo",/^[\)\}\]]+/,null,")]}"],[PR.PR_COMMENT,/^;[^\r\n]*/,null,";"],[PR.PR_PLAIN,/^[\t\n\r \xA0]+/,null,"\t\n\r \u00a0"],[PR.PR_STRING,/^\"(?:[^\"\\]|\\[\s\S])*(?:\"|$)/,null,'"']],[[PR.PR_KEYWORD,/^(?:def|if|do|let|quote|var|fn|loop|recur|throw|try|monitor-enter|monitor-exit|defmacro|defn|defn-|macroexpand|macroexpand-1|for|doseq|dosync|dotimes|and|or|when|not|assert|doto|proxy|defstruct|first|rest|cons|defprotocol|deftype|defrecord|reify|defmulti|defmethod|meta|with-meta|ns|in-ns|create-ns|import|intern|refer|alias|namespace|resolve|ref|deref|refset|new|set!|memfn|to-array|into-array|aset|gen-class|reduce|map|filter|find|nil?|empty?|hash-map|hash-set|vec|vector|seq|flatten|reverse|assoc|dissoc|list|list?|disj|get|union|difference|intersection|extend|extend-type|extend-protocol|prn)\b/,
null],[PR.PR_TYPE,/^:[0-9a-zA-Z\-]+/]]),["clj"]);/*
 Copyright (C) 2009 Google Inc.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
PR.registerLangHandler(PR.createSimpleLexer([[PR.PR_PLAIN,/^[ \t\r\n\f]+/,null," \t\r\n\f"]],[[PR.PR_STRING,/^\"(?:[^\n\r\f\\\"]|\\(?:\r\n?|\n|\f)|\\[\s\S])*\"/,null],[PR.PR_STRING,/^\'(?:[^\n\r\f\\\']|\\(?:\r\n?|\n|\f)|\\[\s\S])*\'/,null],["lang-css-str",/^url\(([^\)\"\']*)\)/i],[PR.PR_KEYWORD,/^(?:url|rgb|\!important|@import|@page|@media|@charset|inherit)(?=[^\-\w]|$)/i,null],["lang-css-kw",/^(-?(?:[_a-z]|(?:\\[0-9a-f]+ ?))(?:[_a-z0-9\-]|\\(?:\\[0-9a-f]+ ?))*)\s*:/i],[PR.PR_COMMENT,/^\/\*[^*]*\*+(?:[^\/*][^*]*\*+)*\//],
[PR.PR_COMMENT,/^(?:\x3c!--|--\x3e)/],[PR.PR_LITERAL,/^(?:\d+|\d*\.\d+)(?:%|[a-z]+)?/i],[PR.PR_LITERAL,/^#(?:[0-9a-f]{3}){1,2}/i],[PR.PR_PLAIN,/^-?(?:[_a-z]|(?:\\[\da-f]+ ?))(?:[_a-z\d\-]|\\(?:\\[\da-f]+ ?))*/i],[PR.PR_PUNCTUATION,/^[^\s\w\'\"]+/]]),["css"]);PR.registerLangHandler(PR.createSimpleLexer([],[[PR.PR_KEYWORD,/^-?(?:[_a-z]|(?:\\[\da-f]+ ?))(?:[_a-z\d\-]|\\(?:\\[\da-f]+ ?))*/i]]),["css-kw"]);PR.registerLangHandler(PR.createSimpleLexer([],[[PR.PR_STRING,/^[^\)\"\']+/]]),["css-str"]);/*
 Copyright (C) 2010 Google Inc.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
PR.registerLangHandler(PR.createSimpleLexer([[PR.PR_PLAIN,/^[\t\n\r \xA0]+/,null,"\t\n\r \u00a0"],[PR.PR_PLAIN,/^(?:\"(?:[^\"\\]|\\[\s\S])*(?:\"|$)|\'(?:[^\'\\]|\\[\s\S])+(?:\'|$))/,null,"\"'"]],[[PR.PR_COMMENT,/^(?:\/\/[^\r\n]*|\/\*[\s\S]*?\*\/)/],[PR.PR_PLAIN,/^(?:[^\/\"\']|\/(?![\/\*]))+/i]]),["go"]);/*
 Copyright (C) 2009 Google Inc.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
PR.registerLangHandler(PR.createSimpleLexer([[PR.PR_PLAIN,/^[\t\n\x0B\x0C\r ]+/,null,"\t\n\x0B\f\r "],[PR.PR_STRING,/^\"(?:[^\"\\\n\x0C\r]|\\[\s\S])*(?:\"|$)/,null,'"'],[PR.PR_STRING,/^\'(?:[^\'\\\n\x0C\r]|\\[^&])\'?/,null,"'"],[PR.PR_LITERAL,/^(?:0o[0-7]+|0x[\da-f]+|\d+(?:\.\d+)?(?:e[+\-]?\d+)?)/i,null,"0123456789"]],[[PR.PR_COMMENT,/^(?:(?:--+(?:[^\r\n\x0C]*)?)|(?:\{-(?:[^-]|-+[^-\}])*-\}))/],[PR.PR_KEYWORD,/^(?:case|class|data|default|deriving|do|else|if|import|in|infix|infixl|infixr|instance|let|module|newtype|of|then|type|where|_)(?=[^a-zA-Z0-9\']|$)/,
null],[PR.PR_PLAIN,/^(?:[A-Z][\w\']*\.)*[a-zA-Z][\w\']*/],[PR.PR_PUNCTUATION,/^[^\t\n\x0B\x0C\r a-zA-Z0-9\'\"]+/]]),["hs"]);/*
 Copyright (C) 2008 Google Inc.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
PR.registerLangHandler(PR.createSimpleLexer([["opn",/^\(+/,null,"("],["clo",/^\)+/,null,")"],[PR.PR_COMMENT,/^;[^\r\n]*/,null,";"],[PR.PR_PLAIN,/^[\t\n\r \xA0]+/,null,"\t\n\r \u00a0"],[PR.PR_STRING,/^\"(?:[^\"\\]|\\[\s\S])*(?:\"|$)/,null,'"']],[[PR.PR_KEYWORD,/^(?:block|c[ad]+r|catch|con[ds]|def(?:ine|un)|do|eq|eql|equal|equalp|eval-when|flet|format|go|if|labels|lambda|let|load-time-value|locally|macrolet|multiple-value-call|nil|progn|progv|quote|require|return-from|setq|symbol-macrolet|t|tagbody|the|throw|unwind)\b/,
null],[PR.PR_LITERAL,/^[+\-]?(?:[0#]x[0-9a-f]+|\d+\/\d+|(?:\.\d+|\d+(?:\.\d*)?)(?:[ed][+\-]?\d+)?)/i],[PR.PR_LITERAL,/^\'(?:-*(?:\w|\\[\x21-\x7e])(?:[\w-]*|\\[\x21-\x7e])[=!?]?)?/],[PR.PR_PLAIN,/^-*(?:[a-z_]|\\[\x21-\x7e])(?:[\w-]*|\\[\x21-\x7e])[=!?]?/i],[PR.PR_PUNCTUATION,/^[^\w\t\n\r \xA0()\"\\\';]+/]]),["cl","el","lisp","scm"]);/*
 Copyright (C) 2008 Google Inc.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
PR.registerLangHandler(PR.createSimpleLexer([[PR.PR_PLAIN,/^[\t\n\r \xA0]+/,null,"\t\n\r \u00a0"],[PR.PR_STRING,/^(?:\"(?:[^\"\\]|\\[\s\S])*(?:\"|$)|\'(?:[^\'\\]|\\[\s\S])*(?:\'|$))/,null,"\"'"]],[[PR.PR_COMMENT,/^--(?:\[(=*)\[[\s\S]*?(?:\]\1\]|$)|[^\r\n]*)/],[PR.PR_STRING,/^\[(=*)\[[\s\S]*?(?:\]\1\]|$)/],[PR.PR_KEYWORD,/^(?:and|break|do|else|elseif|end|false|for|function|if|in|local|nil|not|or|repeat|return|then|true|until|while)\b/,null],[PR.PR_LITERAL,/^[+-]?(?:0x[\da-f]+|(?:(?:\.\d+|\d+(?:\.\d*)?)(?:e[+\-]?\d+)?))/i],
[PR.PR_PLAIN,/^[a-z_]\w*/i],[PR.PR_PUNCTUATION,/^[^\w\t\n\r \xA0][^\w\t\n\r \xA0\"\'\-\+=]*/]]),["lua"]);/*
 Copyright (C) 2008 Google Inc.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
PR.registerLangHandler(PR.createSimpleLexer([[PR.PR_PLAIN,/^[\t\n\r \xA0]+/,null,"\t\n\r \u00a0"],[PR.PR_COMMENT,/^#(?:if[\t\n\r \xA0]+(?:[a-z_$][\w\']*|``[^\r\n\t`]*(?:``|$))|else|endif|light)/i,null,"#"],[PR.PR_STRING,/^(?:\"(?:[^\"\\]|\\[\s\S])*(?:\"|$)|\'(?:[^\'\\]|\\[\s\S])(?:\'|$))/,null,"\"'"]],[[PR.PR_COMMENT,/^(?:\/\/[^\r\n]*|\(\*[\s\S]*?\*\))/],[PR.PR_KEYWORD,/^(?:abstract|and|as|assert|begin|class|default|delegate|do|done|downcast|downto|elif|else|end|exception|extern|false|finally|for|fun|function|if|in|inherit|inline|interface|internal|lazy|let|match|member|module|mutable|namespace|new|null|of|open|or|override|private|public|rec|return|static|struct|then|to|true|try|type|upcast|use|val|void|when|while|with|yield|asr|land|lor|lsl|lsr|lxor|mod|sig|atomic|break|checked|component|const|constraint|constructor|continue|eager|event|external|fixed|functor|global|include|method|mixin|object|parallel|process|protected|pure|sealed|trait|virtual|volatile)\b/],
[PR.PR_LITERAL,/^[+\-]?(?:0x[\da-f]+|(?:(?:\.\d+|\d+(?:\.\d*)?)(?:e[+\-]?\d+)?))/i],[PR.PR_PLAIN,/^(?:[a-z_][\w']*[!?#]?|``[^\r\n\t`]*(?:``|$))/i],[PR.PR_PUNCTUATION,/^[^\t\n\r \xA0\"\'\w]+/]]),["fs","ml"]);/*
 Copyright (C) 2006 Google Inc.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
PR.registerLangHandler(PR.sourceDecorator({keywords:"bool bytes default double enum extend extensions false fixed32 fixed64 float group import int32 int64 max message option optional package repeated required returns rpc service sfixed32 sfixed64 sint32 sint64 string syntax to true uint32 uint64",cStyleComments:!0}),["proto"]);/*
 Copyright (C) 2010 Google Inc.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
PR.registerLangHandler(PR.createSimpleLexer([[PR.PR_PLAIN,/^[\t\n\r \xA0]+/,null,"\t\n\r \u00a0"],[PR.PR_STRING,/^(?:"(?:(?:""(?:""?(?!")|[^\\"]|\\.)*"{0,3})|(?:[^"\r\n\\]|\\.)*"?))/,null,'"'],[PR.PR_LITERAL,/^`(?:[^\r\n\\`]|\\.)*`?/,null,"`"],[PR.PR_PUNCTUATION,/^[!#%&()*+,\-:;<=>?@\[\\\]^{|}~]+/,null,"!#%&()*+,-:;<=>?@[\\]^{|}~"]],[[PR.PR_STRING,/^'(?:[^\r\n\\']|\\(?:'|[^\r\n']+))'/],[PR.PR_LITERAL,/^'[a-zA-Z_$][\w$]*(?!['$\w])/],[PR.PR_KEYWORD,/^(?:abstract|case|catch|class|def|do|else|extends|final|finally|for|forSome|if|implicit|import|lazy|match|new|object|override|package|private|protected|requires|return|sealed|super|throw|trait|try|type|val|var|while|with|yield)\b/],
[PR.PR_LITERAL,/^(?:true|false|null|this)\b/],[PR.PR_LITERAL,/^(?:(?:0(?:[0-7]+|X[0-9A-F]+))L?|(?:(?:0|[1-9][0-9]*)(?:(?:\.[0-9]+)?(?:E[+\-]?[0-9]+)?F?|L?))|\\.[0-9]+(?:E[+\-]?[0-9]+)?F?)/i],[PR.PR_TYPE,/^[$_]*[A-Z][_$A-Z0-9]*[a-z][\w$]*/],[PR.PR_PLAIN,/^[$a-zA-Z_][\w$]*/],[PR.PR_COMMENT,/^\/(?:\/.*|\*(?:\/|\**[^*/])*(?:\*+\/?)?)/],[PR.PR_PUNCTUATION,/^(?:\.+|\/)/]]),["scala"]);/*
 Copyright (C) 2008 Google Inc.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
PR.registerLangHandler(PR.createSimpleLexer([[PR.PR_PLAIN,/^[\t\n\r \xA0]+/,null,"\t\n\r \u00a0"],[PR.PR_STRING,/^(?:"(?:[^\"\\]|\\.)*"|'(?:[^\'\\]|\\.)*')/,null,"\"'"]],[[PR.PR_COMMENT,/^(?:--[^\r\n]*|\/\*[\s\S]*?(?:\*\/|$))/],[PR.PR_KEYWORD,/^(?:ADD|ALL|ALTER|AND|ANY|AS|ASC|AUTHORIZATION|BACKUP|BEGIN|BETWEEN|BREAK|BROWSE|BULK|BY|CASCADE|CASE|CHECK|CHECKPOINT|CLOSE|CLUSTERED|COALESCE|COLLATE|COLUMN|COMMIT|COMPUTE|CONSTRAINT|CONTAINS|CONTAINSTABLE|CONTINUE|CONVERT|CREATE|CROSS|CURRENT|CURRENT_DATE|CURRENT_TIME|CURRENT_TIMESTAMP|CURRENT_USER|CURSOR|DATABASE|DBCC|DEALLOCATE|DECLARE|DEFAULT|DELETE|DENY|DESC|DISK|DISTINCT|DISTRIBUTED|DOUBLE|DROP|DUMMY|DUMP|ELSE|END|ERRLVL|ESCAPE|EXCEPT|EXEC|EXECUTE|EXISTS|EXIT|FETCH|FILE|FILLFACTOR|FOR|FOREIGN|FREETEXT|FREETEXTTABLE|FROM|FULL|FUNCTION|GOTO|GRANT|GROUP|HAVING|HOLDLOCK|IDENTITY|IDENTITYCOL|IDENTITY_INSERT|IF|IN|INDEX|INNER|INSERT|INTERSECT|INTO|IS|JOIN|KEY|KILL|LEFT|LIKE|LINENO|LOAD|NATIONAL|NOCHECK|NONCLUSTERED|NOT|NULL|NULLIF|OF|OFF|OFFSETS|ON|OPEN|OPENDATASOURCE|OPENQUERY|OPENROWSET|OPENXML|OPTION|OR|ORDER|OUTER|OVER|PERCENT|PLAN|PRECISION|PRIMARY|PRINT|PROC|PROCEDURE|PUBLIC|RAISERROR|READ|READTEXT|RECONFIGURE|REFERENCES|REPLICATION|RESTORE|RESTRICT|RETURN|REVOKE|RIGHT|ROLLBACK|ROWCOUNT|ROWGUIDCOL|RULE|SAVE|SCHEMA|SELECT|SESSION_USER|SET|SETUSER|SHUTDOWN|SOME|STATISTICS|SYSTEM_USER|TABLE|TEXTSIZE|THEN|TO|TOP|TRAN|TRANSACTION|TRIGGER|TRUNCATE|TSEQUAL|UNION|UNIQUE|UPDATE|UPDATETEXT|USE|USER|VALUES|VARYING|VIEW|WAITFOR|WHEN|WHERE|WHILE|WITH|WRITETEXT)(?=[^\w-]|$)/i,
null],[PR.PR_LITERAL,/^[+-]?(?:0x[\da-f]+|(?:(?:\.\d+|\d+(?:\.\d*)?)(?:e[+\-]?\d+)?))/i],[PR.PR_PLAIN,/^[a-z_][\w-]*/i],[PR.PR_PUNCTUATION,/^[^\w\t\n\r \xA0\"\'][^\w\t\n\r \xA0+\-\"\']*/]]),["sql"]);/*
 Copyright (C) 2009 Google Inc.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
PR.registerLangHandler(PR.createSimpleLexer([[PR.PR_PLAIN,/^[\t\n\r \xA0\u2028\u2029]+/,null,"\t\n\r \u00a0\u2028\u2029"],[PR.PR_STRING,/^(?:[\"\u201C\u201D](?:[^\"\u201C\u201D]|[\"\u201C\u201D]{2})(?:[\"\u201C\u201D]c|$)|[\"\u201C\u201D](?:[^\"\u201C\u201D]|[\"\u201C\u201D]{2})*(?:[\"\u201C\u201D]|$))/i,null,'"\u201c\u201d'],[PR.PR_COMMENT,/^[\'\u2018\u2019][^\r\n\u2028\u2029]*/,null,"'\u2018\u2019"]],[[PR.PR_KEYWORD,/^(?:AddHandler|AddressOf|Alias|And|AndAlso|Ansi|As|Assembly|Auto|Boolean|ByRef|Byte|ByVal|Call|Case|Catch|CBool|CByte|CChar|CDate|CDbl|CDec|Char|CInt|Class|CLng|CObj|Const|CShort|CSng|CStr|CType|Date|Decimal|Declare|Default|Delegate|Dim|DirectCast|Do|Double|Each|Else|ElseIf|End|EndIf|Enum|Erase|Error|Event|Exit|Finally|For|Friend|Function|Get|GetType|GoSub|GoTo|Handles|If|Implements|Imports|In|Inherits|Integer|Interface|Is|Let|Lib|Like|Long|Loop|Me|Mod|Module|MustInherit|MustOverride|MyBase|MyClass|Namespace|New|Next|Not|NotInheritable|NotOverridable|Object|On|Option|Optional|Or|OrElse|Overloads|Overridable|Overrides|ParamArray|Preserve|Private|Property|Protected|Public|RaiseEvent|ReadOnly|ReDim|RemoveHandler|Resume|Return|Select|Set|Shadows|Shared|Short|Single|Static|Step|Stop|String|Structure|Sub|SyncLock|Then|Throw|To|Try|TypeOf|Unicode|Until|Variant|Wend|When|While|With|WithEvents|WriteOnly|Xor|EndIf|GoSub|Let|Variant|Wend)\b/i,
null],[PR.PR_COMMENT,/^REM[^\r\n\u2028\u2029]*/i],[PR.PR_LITERAL,/^(?:True\b|False\b|Nothing\b|\d+(?:E[+\-]?\d+[FRD]?|[FRDSIL])?|(?:&H[0-9A-F]+|&O[0-7]+)[SIL]?|\d*\.\d+(?:E[+\-]?\d+)?[FRD]?|#\s+(?:\d+[\-\/]\d+[\-\/]\d+(?:\s+\d+:\d+(?::\d+)?(\s*(?:AM|PM))?)?|\d+:\d+(?::\d+)?(\s*(?:AM|PM))?)\s+#)/i],[PR.PR_PLAIN,/^(?:(?:[a-z]|_\w)\w*|\[(?:[a-z]|_\w)\w*\])/i],[PR.PR_PUNCTUATION,/^[^\w\t\n\r \"\'\[\]\xA0\u2018\u2019\u201C\u201D\u2028\u2029]+/],[PR.PR_PUNCTUATION,/^(?:\[|\])/]]),["vb","vbs"]);PR.registerLangHandler(PR.createSimpleLexer([[PR.PR_PLAIN,/^[\t\n\r \xA0]+/,null,"\t\n\r \u00a0"]],[[PR.PR_STRING,/^(?:[BOX]?"(?:[^\"]|"")*"|'.')/i],[PR.PR_COMMENT,/^--[^\r\n]*/],[PR.PR_KEYWORD,/^(?:abs|access|after|alias|all|and|architecture|array|assert|attribute|begin|block|body|buffer|bus|case|component|configuration|constant|disconnect|downto|else|elsif|end|entity|exit|file|for|function|generate|generic|group|guarded|if|impure|in|inertial|inout|is|label|library|linkage|literal|loop|map|mod|nand|new|next|nor|not|null|of|on|open|or|others|out|package|port|postponed|procedure|process|pure|range|record|register|reject|rem|report|return|rol|ror|select|severity|shared|signal|sla|sll|sra|srl|subtype|then|to|transport|type|unaffected|units|until|use|variable|wait|when|while|with|xnor|xor)(?=[^\w-]|$)/i,
null],[PR.PR_TYPE,/^(?:bit|bit_vector|character|boolean|integer|real|time|string|severity_level|positive|natural|signed|unsigned|line|text|std_u?logic(?:_vector)?)(?=[^\w-]|$)/i,null],[PR.PR_TYPE,/^\'(?:ACTIVE|ASCENDING|BASE|DELAYED|DRIVING|DRIVING_VALUE|EVENT|HIGH|IMAGE|INSTANCE_NAME|LAST_ACTIVE|LAST_EVENT|LAST_VALUE|LEFT|LEFTOF|LENGTH|LOW|PATH_NAME|POS|PRED|QUIET|RANGE|REVERSE_RANGE|RIGHT|RIGHTOF|SIMPLE_NAME|STABLE|SUCC|TRANSACTION|VAL|VALUE)(?=[^\w-]|$)/i,null],[PR.PR_LITERAL,/^\d+(?:_\d+)*(?:#[\w\\.]+#(?:[+\-]?\d+(?:_\d+)*)?|(?:\.\d+(?:_\d+)*)?(?:E[+\-]?\d+(?:_\d+)*)?)/i],
[PR.PR_PLAIN,/^(?:[a-z]\w*|\\[^\\]*\\)/i],[PR.PR_PUNCTUATION,/^[^\w\t\n\r \xA0\"\'][^\w\t\n\r \xA0\-\"\']*/]]),["vhdl","vhd"]);/*
 Copyright (C) 2009 Google Inc.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
PR.registerLangHandler(PR.createSimpleLexer([[PR.PR_PLAIN,/^[\t \xA0a-gi-z0-9]+/,null,"\t \u00a0abcdefgijklmnopqrstuvwxyz0123456789"],[PR.PR_PUNCTUATION,/^[=*~\^\[\]]+/,null,"=*~^[]"]],[["lang-wiki.meta",/(?:^^|\r\n?|\n)(#[a-z]+)\b/],[PR.PR_LITERAL,/^(?:[A-Z][a-z][a-z0-9]+[A-Z][a-z][a-zA-Z0-9]+)\b/],["lang-",/^\{\{\{([\s\S]+?)\}\}\}/],["lang-",/^`([^\r\n`]+)`/],[PR.PR_STRING,/^https?:\/\/[^\/?#\s]*(?:\/[^?#\s]*)?(?:\?[^#\s]*)?(?:#\S*)?/i],[PR.PR_PLAIN,/^(?:\r\n|[\s\S])[^#=*~^A-Zh\{`\[\r\n]*/]]),["wiki"]);
PR.registerLangHandler(PR.createSimpleLexer([[PR.PR_KEYWORD,/^#[a-z]+/i,null,"#"]],[]),["wiki.meta"]);PR.registerLangHandler(PR.createSimpleLexer([[PR.PR_PUNCTUATION,/^[:|>?]+/,null,":|>?"],[PR.PR_DECLARATION,/^%(?:YAML|TAG)[^#\r\n]+/,null,"%"],[PR.PR_TYPE,/^[&]\S+/,null,"&"],[PR.PR_TYPE,/^!\S*/,null,"!"],[PR.PR_STRING,/^"(?:[^\\"]|\\.)*(?:"|$)/,null,'"'],[PR.PR_STRING,/^'(?:[^']|'')*(?:'|$)/,null,"'"],[PR.PR_COMMENT,/^#[^\r\n]*/,null,"#"],[PR.PR_PLAIN,/^\s+/,null," \t\r\n"]],[[PR.PR_DECLARATION,/^(?:---|\.\.\.)(?:[\r\n]|$)/],[PR.PR_PUNCTUATION,/^-/],[PR.PR_KEYWORD,/^\w+:[ \r\n]/],[PR.PR_PLAIN,/^\w+/]]),
["yaml","yml"]);
})();

    
   prettyPrint();
  }
    //]]></script>
<pre class="prettyprint lang-c"><span class="com">/*<br>&nbsp;* estructurasPackage.h<br>&nbsp;*<br>&nbsp;* &nbsp;Created on: 11/05/2013<br>&nbsp;* &nbsp; &nbsp; &nbsp;Author: utnso<br>&nbsp;*/</span><span class="pln"><br><br></span><span class="com">#ifndef</span><span class="pln"> ESTRUCTURASPACKAGE_H_<br></span><span class="com">#define</span><span class="pln"> ESTRUCTURASPACKAGE_H_<br><br></span><span class="com">#include</span><span class="pln"> </span><span class="str">"collections/list.h"</span><span class="pln"><br><br></span><span class="com">/* Defino los tipos de se��ales que se pueden mandar<br>&nbsp;*<br>&nbsp;* Sintaxis correcta para escribir una nueva se��al:<br>&nbsp;*<br>&nbsp;* &nbsp; &nbsp; &nbsp;#define S_[Origen]_[Destino]_[Mensaje] numeroIncremental<br>&nbsp;*<br>&nbsp;* &nbsp; &nbsp; &nbsp;Donde:<br>&nbsp;* &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;[Origen] es quien manda el mensaje<br>&nbsp;* &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;[Destino] es quien recibe el mensaje<br>&nbsp;* &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;[Mensaje] lo que se le quiere mandar<br>&nbsp;* &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;numeroIncrementar un numero mas que la se��al anterior<br>&nbsp;*/</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> S_ERROR </span><span class="lit">0</span><span class="pln"> &nbsp; &nbsp; &nbsp; </span><span class="com">// Utilizada en socket_recibirSe��al, para decir que lo que se recibio no era una se��al</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> S_Personaje_Nivel_MoverIzquierda </span><span class="lit">1</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> S_Personaje_Nivel_MoverDerecha </span><span class="lit">2</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> S_Personaje_Nivel_MoverArriba </span><span class="lit">3</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> S_Personaje_Nivel_MoverAbajo </span><span class="lit">4</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> S_Planificador_Personaje_HabilitarMover </span><span class="lit">5</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> S_Planificador_Personaje_Matate </span><span class="lit">6</span><span class="pln"> &nbsp; &nbsp; &nbsp; </span><span class="com">//Esta la manda el orquestador, pero usando el fd que tiene guardado el planificador, entonces al personaje le va a parecer que lo dijo el planificador.</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> S_Personaje_Planificador_MeMovi </span><span class="lit">7</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> S_Personaje_Orquestador_EmpeceJuego </span><span class="lit">8</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> S_Personaje_Planificador_MeMoviYTomeRecurso </span><span class="lit">9</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> S_Personaje_Orquestador_TermineJuego </span><span class="lit">10</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> S_Personaje_Nivel_PedirPosicionRecurso </span><span class="lit">11</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> S_Nivel_Personaje_ConfirmaQueSeMovio </span><span class="lit">12</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> S_Personaje_Nivel_PedirRecurso </span><span class="lit">13</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> S_Nivel_Personaje_TeAsigneRecurso </span><span class="lit">14</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> S_Nivel_Personaje_NoTeAsigneRecurso </span><span class="lit">15</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> S_Personaje_Orquestador_DameDireccionDeNivel </span><span class="lit">16</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> S_Personaje_Nivel_Reiniciar </span><span class="lit">17</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> S_Personaje_Planificador_Reiniciar </span><span class="lit">18</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> S_Orquestador_Nivel_Finalizate </span><span class="lit">19</span><span class="pln"><br><br></span><span class="com">/*Defino las estructuras de los paquetes<br>&nbsp;*<br>&nbsp;* Sintaxis correcta para escribir un nuev mensaje:<br>&nbsp;*<br>&nbsp;* &nbsp; &nbsp; &nbsp;#define D_STRUCT_[Nombre Estructura]<br>&nbsp;*<br>&nbsp;* &nbsp; &nbsp; &nbsp;Donde:<br>&nbsp;* &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;[Nombre Estructura] es el nombre de la estructura en MAYUSCULA<br>&nbsp;*<br>&nbsp;* &nbsp; &nbsp; &nbsp;Nota:<br>&nbsp;* &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;No olvidarse de crear la estructura y su paquetizador y despaquetizador asociado!<br>&nbsp;*/</span><span class="pln"><br><br></span><span class="com">#define</span><span class="pln"> D_STRUCT_NOMBREMENSAJE </span><span class="lit">0</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> D_STRUCT_NUMERO </span><span class="lit">1</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> D_STRUCT_CHAR </span><span class="lit">2</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> D_STRUCT_STRING </span><span class="lit">3</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> D_STRUCT_POSXPOSY </span><span class="lit">4</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> D_STRUCT_SIGNAL </span><span class="lit">5</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> D_STRUCT_DIRECCIONES </span><span class="lit">6</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> D_STRUCT_PEDIRRECURSO </span><span class="lit">7</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> D_STRUCT_PEDIRPOSICIONRECURSO </span><span class="lit">8</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> D_STRUCT_DATOSNIVEL </span><span class="lit">9</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> D_STRUCT_SIMBOLOPERSONAJE </span><span class="lit">10</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> D_STRUCT_NOMBRENIVEL </span><span class="lit">11</span><span class="pln"> </span><span class="com">//de tipo t_struct_string</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> D_STRUCT_PERSONAJESINTERBLOQUEADOS </span><span class="lit">12</span><span class="pln"> </span><span class="com">//de tipo t_struct_string (de nivel a orque)</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> D_STRUCT_RECURSOSLIBERADOS </span><span class="lit">13</span><span class="pln"> </span><span class="com">//de tipo t_struct_string</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> D_STRUCT_RECURSOBLOQUEANTE </span><span class="lit">14</span><span class="pln"> </span><span class="com">//se lo manda el personaje al plani;</span><span class="pln"><br></span><span class="com">#define</span><span class="pln"> D_STRUCT_RECURSOSASIGNADOSYSOBRANTES </span><span class="lit">15</span><span class="pln"> </span><span class="com">//dos strings</span><span class="pln"><br><br></span><span class="com">//Estructura auxiliar de stream</span><span class="pln"><br></span><span class="kwd">typedef</span><span class="pln"> </span><span class="kwd">struct</span><span class="pln"> </span><span class="pun">{</span><span class="pln"><br>&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="kwd">int</span><span class="pln"> length</span><span class="pun">;</span><span class="pln"><br>&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="kwd">char</span><span class="pln"> </span><span class="pun">*</span><span class="pln">data</span><span class="pun">;</span><span class="pln"><br></span><span class="pun">}</span><span class="pln"> t_stream</span><span class="pun">;</span><span class="pln"><br><br></span><span class="com">// Header de stream</span><span class="pln"><br></span><span class="kwd">typedef</span><span class="pln"> </span><span class="kwd">struct</span><span class="pln"> </span><span class="pun">{</span><span class="pln"><br>&nbsp; &nbsp; &nbsp; &nbsp; uint8_t tipoEstructura</span><span class="pun">;</span><span class="pln"><br>&nbsp; &nbsp; &nbsp; &nbsp; uint16_t length</span><span class="pun">;</span><span class="pln"><br></span><span class="pun">}</span><span class="pln"> __attribute__ </span><span class="pun">((</span><span class="pln">__packed__</span><span class="pun">))</span><span class="pln"> t_header</span><span class="pun">;</span><span class="pln"><br><br><br></span><span class="com">/*<br>&nbsp;* &nbsp; &nbsp; &nbsp;TYPEDEF DE LAS ESTRUCTURAS A ENVIAR<br>&nbsp;*/</span><span class="pln"><br><br></span><span class="com">//Estructura tipo STRUCT_NOMBREMENSAJE(0)</span><span class="pln"><br></span><span class="kwd">typedef</span><span class="pln"> </span><span class="kwd">struct</span><span class="pln"> struct_nombreMensaje </span><span class="pun">{</span><span class="pln"><br>&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="kwd">char</span><span class="pln"> </span><span class="pun">*</span><span class="pln"> nombre</span><span class="pun">;</span><span class="pln"><br>&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="kwd">char</span><span class="pln"> </span><span class="pun">*</span><span class="pln"> mensaje</span><span class="pun">;</span><span class="pln"><br></span><span class="pun">}</span><span class="pln"> __attribute__ </span><span class="pun">((</span><span class="pln">__packed__</span><span class="pun">))</span><span class="pln"> t_struct_nombreMensaje</span><span class="pun">;</span><span class="pln"><br><br></span><span class="com">//Estructura tipo STRUCT_NUMERO(1)</span><span class="pln"><br></span><span class="kwd">typedef</span><span class="pln"> </span><span class="kwd">struct</span><span class="pln"> struct_numero </span><span class="pun">{</span><span class="pln"><br>&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="kwd">unsigned</span><span class="pln"> </span><span class="kwd">int</span><span class="pln"> numero</span><span class="pun">;</span><span class="pln"><br></span><span class="pun">}</span><span class="pln"> __attribute__ </span><span class="pun">((</span><span class="pln">__packed__</span><span class="pun">))</span><span class="pln"> t_struct_numero</span><span class="pun">;</span><span class="pln"><br><br></span><span class="com">//Estructura tipo STRUCT_CHAR(2)</span><span class="pln"><br></span><span class="kwd">typedef</span><span class="pln"> </span><span class="kwd">struct</span><span class="pln"> struct_char </span><span class="pun">{</span><span class="pln"><br>&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="kwd">char</span><span class="pln"> letra</span><span class="pun">;</span><span class="pln"><br></span><span class="pun">}</span><span class="pln"> __attribute__ </span><span class="pun">((</span><span class="pln">__packed__</span><span class="pun">))</span><span class="pln"> t_struct_char</span><span class="pun">;</span><span class="pln"><br><br></span><span class="com">//Estructura tipo STRUCT_STRING(3)</span><span class="pln"><br></span><span class="kwd">typedef</span><span class="pln"> </span><span class="kwd">struct</span><span class="pln"> struct_string </span><span class="pun">{</span><span class="pln"><br>&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="kwd">char</span><span class="pln"> </span><span class="pun">*</span><span class="pln"> string</span><span class="pun">;</span><span class="pln"><br></span><span class="pun">}</span><span class="pln"> __attribute__ </span><span class="pun">((</span><span class="pln">__packed__</span><span class="pun">))</span><span class="pln"> t_struct_string</span><span class="pun">;</span><span class="pln"><br><br></span><span class="com">/*Estructura tipo STRUCT_POSXPOSY(4)<br>&nbsp;* Va a enviar la posicion en x y en y (dos unsigned int) en la que se encuentra el personaje o el recurso.<br>&nbsp;*/</span><span class="pln"><br></span><span class="kwd">typedef</span><span class="pln"> </span><span class="kwd">struct</span><span class="pln"> struct_posxposy </span><span class="pun">{</span><span class="pln"><br>&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="kwd">unsigned</span><span class="pln"> </span><span class="kwd">int</span><span class="pln"> posX</span><span class="pun">;</span><span class="pln"><br>&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="kwd">unsigned</span><span class="pln"> </span><span class="kwd">int</span><span class="pln"> posY</span><span class="pun">;</span><span class="pln"><br></span><span class="pun">}</span><span class="pln"> __attribute__ </span><span class="pun">((</span><span class="pln">__packed__</span><span class="pun">))</span><span class="pln"> t_struct_posxposy</span><span class="pun">;</span><span class="pln"><br><br><br></span><span class="com">/*Estructura tipo STRUCT_SIGNAL(5)<br>&nbsp;* se va a usar cuando quiera enviar una se��al.<br>&nbsp;* cada se��al va a estar numerada. Entonces aca envio el nro de se��al.<br>&nbsp;*/</span><span class="pln"><br></span><span class="kwd">typedef</span><span class="pln"> </span><span class="kwd">unsigned</span><span class="pln"> </span><span class="kwd">int</span><span class="pln"> t_signal</span><span class="pun">;</span><span class="pln"><br><br></span><span class="kwd">typedef</span><span class="pln"> </span><span class="kwd">struct</span><span class="pln"> struct_signal </span><span class="pun">{</span><span class="pln"><br>&nbsp; &nbsp; &nbsp; &nbsp; t_signal signal</span><span class="pun">;</span><span class="pln"><br></span><span class="pun">}</span><span class="pln"> __attribute__ </span><span class="pun">((</span><span class="pln">__packed__</span><span class="pun">))</span><span class="pln"> t_struct_signal</span><span class="pun">;</span><span class="pln"><br><br><br></span><span class="com">/*Estructura tipo STRUCT_DIRECCIONES(6)<br>&nbsp;* se va a enviar dos string (char*) con la direccion ip y puerto de nivel y planificador.<br>&nbsp;*/</span><span class="pln"><br></span><span class="kwd">typedef</span><span class="pln"> </span><span class="kwd">struct</span><span class="pln"> </span><span class="pun">{</span><span class="pln"><br>&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="kwd">char</span><span class="pln"> </span><span class="pun">*</span><span class="pln"> direccionNivel</span><span class="pun">;</span><span class="pln"><br>&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="kwd">char</span><span class="pln"> </span><span class="pun">*</span><span class="pln"> direccionPlanificador</span><span class="pun">;</span><span class="pln"><br></span><span class="pun">}</span><span class="pln"> &nbsp;__attribute__ </span><span class="pun">((</span><span class="pln">__packed__</span><span class="pun">))</span><span class="pln"> t_struct_direcciones</span><span class="pun">;</span><span class="pln"><br><br></span><span class="com">//Estructura tipo STRUCT_PEDIRRECURSO (7)</span><span class="pln"><br></span><span class="kwd">typedef</span><span class="pln"> </span><span class="kwd">struct</span><span class="pln"> struct_pedirRecurso </span><span class="pun">{</span><span class="pln"><br>&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="kwd">char</span><span class="pln"> letra</span><span class="pun">;</span><span class="pln"><br></span><span class="pun">}</span><span class="pln"> __attribute__ </span><span class="pun">((</span><span class="pln">__packed__</span><span class="pun">))</span><span class="pln"> t_struct_pedirRecurso</span><span class="pun">;</span><span class="pln"><br><br><br></span><span class="com">//Estructura tipo STRUCT_PEDIRPOSICIONRECURSO(8)</span><span class="pln"><br></span><span class="kwd">typedef</span><span class="pln"> </span><span class="kwd">struct</span><span class="pln"> struct_pedirPosicionRecurs </span><span class="pun">{</span><span class="pln"><br>&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="kwd">char</span><span class="pln"> letra</span><span class="pun">;</span><span class="pln"><br></span><span class="pun">}</span><span class="pln"> __attribute__ </span><span class="pun">((</span><span class="pln">__packed__</span><span class="pun">))</span><span class="pln"> t_struct_pedirPosicionRecurso</span><span class="pun">;</span><span class="pln"><br><br><br></span><span class="com">/*Estructura tipo STRUCT_DATOSNIVEL(9)<br>&nbsp;* Se usa en orquestador, para conectar un nivel.<br>&nbsp;*/</span><span class="pln"><br></span><span class="kwd">typedef</span><span class="pln"> </span><span class="kwd">struct</span><span class="pln"> </span><span class="pun">{</span><span class="pln"><br>&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="kwd">char</span><span class="pln"> </span><span class="pun">*</span><span class="pln"> nombre</span><span class="pun">;</span><span class="pln"><br>&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="kwd">char</span><span class="pln"> </span><span class="pun">*</span><span class="pln"> direccion</span><span class="pun">;</span><span class="pln"><br>&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="kwd">char</span><span class="pln"> </span><span class="pun">*</span><span class="pln"> recursos</span><span class="pun">;</span><span class="pln"><br></span><span class="pun">}</span><span class="pln"> &nbsp;__attribute__ </span><span class="pun">((</span><span class="pln">__packed__</span><span class="pun">))</span><span class="pln"> t_struct_datosNivel</span><span class="pun">;</span><span class="pln"><br><br></span><span class="com">//Estructura tipo STRUCT_SIMBOLOPERSONAJE(10)</span><span class="pln"><br></span><span class="kwd">typedef</span><span class="pln"> </span><span class="kwd">struct</span><span class="pln"> struct_simboloPersonaje </span><span class="pun">{</span><span class="pln"><br>&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="kwd">char</span><span class="pln"> simbolo</span><span class="pun">;</span><span class="pln"><br></span><span class="pun">}</span><span class="pln"> __attribute__ </span><span class="pun">((</span><span class="pln">__packed__</span><span class="pun">))</span><span class="pln"> t_struct_simboloPersonaje</span><span class="pun">;</span><span class="pln"><br><br><br></span><span class="com">/*Estructura tipo STRUCT_NOMBRENIVEL(11)<br>&nbsp;* La usa el personaje para mandarle al orquestador:<br>&nbsp;* se��al: "empec�� juego", con nombre primer nivel<br>&nbsp;* o se��al: "me bloquee", con nombre nivel actual (en el que se bloque��).<br>*/</span><span class="pln"><br></span><span class="kwd">typedef</span><span class="pln"> </span><span class="kwd">struct</span><span class="pln"> struct_nombreNivel </span><span class="pun">{</span><span class="pln"> </span><span class="com">//personaje le manda esta estructura al orquestador, para que le devuelva la struct direcciones del mismo.</span><span class="pln"><br>&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="kwd">char</span><span class="pln"> </span><span class="pun">*</span><span class="pln"> nombre</span><span class="pun">;</span><span class="pln"><br></span><span class="pun">}</span><span class="pln"> __attribute__ </span><span class="pun">((</span><span class="pln">__packed__</span><span class="pun">))</span><span class="pln"> t_struct_nombreNivel</span><span class="pun">;</span><span class="pln"><br><br></span><span class="com">/*Estructura tipo D_STRUCT_PERSONAJESINTERBLOQUEADOS(12)<br>&nbsp;* La usa el nivel para mandarle al orquestador:<br>&nbsp;* la cadena de s��mbolos de los personajes que quedaron interbloqueados<br>*/</span><span class="pln"><br></span><span class="kwd">typedef</span><span class="pln"> </span><span class="kwd">struct</span><span class="pln"> struct_personajesInterbloqueados</span><span class="pun">{</span><span class="pln"><br>&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="kwd">char</span><span class="pln"> </span><span class="pun">*</span><span class="pln"> simbolosPersonajes</span><span class="pun">;</span><span class="pln"><br></span><span class="pun">}</span><span class="pln"> __attribute__ </span><span class="pun">((</span><span class="pln">__packed__</span><span class="pun">))</span><span class="pln"> t_struct_personajesInterbloqueados</span><span class="pun">;</span><span class="pln"><br><br></span><span class="com">/*Estructura tipo D_STRUCT_RECURSOSLIBERADOS(13)<br>&nbsp;* La usa el nivel para mandarle al orquestador:<br>&nbsp;* la cadena de s��mbolos de los recursos liberados por un personaje<br>*/</span><span class="pln"><br></span><span class="kwd">typedef</span><span class="pln"> </span><span class="kwd">struct</span><span class="pln"> struct_recursosLiberados</span><span class="pun">{</span><span class="pln"><br>&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="kwd">char</span><span class="pln"> </span><span class="pun">*</span><span class="pln"> recursosLiberados</span><span class="pun">;</span><span class="pln"><br></span><span class="pun">}</span><span class="pln"> __attribute__ </span><span class="pun">((</span><span class="pln">__packed__</span><span class="pun">))</span><span class="pln"> t_struct_recursosLiberados</span><span class="pun">;</span><span class="pln"><br><br><br></span><span class="com">/*Estructura tipo D_STRUCT_RECURSOBLOQUEANTE(14)<br>&nbsp;* La usa el personaje para mandarle al planificador:<br>&nbsp;* El recurso por el cual se bloqueo. Se infiere con esto<br>&nbsp;* que el personaje esta bloqueado. No se manda signal antes si esta bloqueadoi o no<br>*/</span><span class="pln"><br></span><span class="kwd">typedef</span><span class="pln"> </span><span class="kwd">struct</span><span class="pln"> struct_recursoBloqueante </span><span class="pun">{</span><span class="pln"><br>&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="kwd">char</span><span class="pln"> recurso</span><span class="pun">;</span><span class="pln"><br></span><span class="pun">}</span><span class="pln"> __attribute__ </span><span class="pun">((</span><span class="pln">__packed__</span><span class="pun">))</span><span class="pln"> t_struct_recursoBloqueante</span><span class="pun">;</span><span class="pln"><br><br></span><span class="com">/*Estructura tipo D_STRUCT_RECURSOSASIGNADOSYSOBRANTES(15)<br>&nbsp;* La usa el orquestador para mandarselo al nivel:<br>&nbsp;* la cadena de s��mbolos de los recursos liberados, ej: "MMH"<br>&nbsp;* y los recursos asignados y a quien se los asigno, ej: "@M%H"<br>*/</span><span class="pln"><br></span><span class="kwd">typedef</span><span class="pln"> </span><span class="kwd">struct</span><span class="pln"> struct_recursosAsignadosYSobrantes </span><span class="pun">{</span><span class="pln"><br>&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="kwd">char</span><span class="pln"> </span><span class="pun">*</span><span class="pln"> recursosSobrantes</span><span class="pun">;</span><span class="pln"><br>&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="kwd">char</span><span class="pln"> </span><span class="pun">*</span><span class="pln"> personajeRecurso</span><span class="pun">;</span><span class="pln"> &nbsp; &nbsp; &nbsp; &nbsp;</span><span class="com">//contiene char pesonaje seguido de char recurso, asi repetido por el string</span><span class="pln"><br></span><span class="pun">}</span><span class="pln"> __attribute__ </span><span class="pun">((</span><span class="pln">__packed__</span><span class="pun">))</span><span class="pln"> t_struct_recursosAsignadosYSobrantes</span><span class="pun">;</span><span class="pln"><br><br></span><span class="com">#endif</span><span class="pln"> </span><span class="com">/* ESTRUCTURASPACKAGE_H_ */</span><span class="pln"><br></span></pre>
  <script type="text/javascript">do_pretty_print();</script>
</div>
</div></div>
<div id="loading" style="display: none;">Loading...
<div class="progress-bar-horizontal" role="progressbar" aria-live="polite" aria-valuenow="90"><div id="progress-bar-thumb" class="progress-bar-thumb" style="width: 90%;"></div></div></div>

</div>
</div></div>
<script type="text/javascript" src="./estructurasPackage_files/580548216-gview_local_gview_base_mod__es.js"></script>

<script type="text/javascript">
    
    
    
      
      var _docs_flag_initialData = {"gv_int_native":false,"tpc":true,"buildLabel":"fe_i86-RC4","buildClNumber":"65716200","docs-show_debug_info":false,"ondlburl":"//docs.google.com","drive_url":"//drive.google.com/?authuser\u003d0","docs-ndt":"","enable_kennedy":true,"enable_feedback":false,"enable_feedback_button":false};
    
    var gviewElement = document.getElementById('gview');
    var config = {
      'api': false,
      'csi': true,
      'ddUrl': null,
      'element': gviewElement,
      'embedded': false,
      'efh': true,
      'minimal': false,
      'mobile': false,
      'initialQuery': "",
      'oivUrl': "https://docs.google.com/viewer?pid\x3dexplorer\x26srcid\x3d0B--MFC48AFZiaVNVbVk5NjVrcWJwUm5ySzg1bTVvZ3Boc0Fv\x26docid\x3d40137e45a34faf08f6461849a16891bf%7C7d8d77647de03e113d972c9c08bee823\x26chan\x3dEQAAAH0aw3sahfpagTIgvH9I/9SLYt88h8yB7MTFpbZj80UP\x26a\x3dv\x26rel\x3drar;r14;estructurasPackage.h\x26chrome\x3dtrue",
      'gdUrl' : "http://docs.google.com?authuser\x3d0",
      'pid': "explorer",
      'sh': false,
      
      'userAuthenticated': true,
      'sessId': "0",
      'domain': null,
      'redirMs': 10000
    };

    var gviewApp = _createGView(config);
    gviewApp.setProgress(50);
    
      
        
        
          window.jstiming.load.name = 'view';
        
      
      
      window.jstiming.load.tick('_dt');
    

    
    window.onresize = window.onorientationchange = handleResize;

    document.body.onunload = dispose;

    function handleResize(e) {
      resizeApp(false);
    };

    function resizeApp(force) {
      if (gviewApp) {
        var viewportSize = getViewportSize();
        var gviewOffset = getPageOffset(gviewElement);
        viewportSize.height = Math.max(
            viewportSize.height - gviewOffset.y, 0);
        gviewApp.resize(viewportSize, force);
      }
    };

    function dispose() {
      window.onresize = null;
      if (gviewApp) {
        gviewApp.dispose();
        gviewApp = null;
      }
    };
  </script>


<link rel="shortcut icon" href="https://ssl.gstatic.com/docs/doclist/images/icon_9_generic_favicon.ico">
<script type="text/javascript">
    gviewApp.setFileData({expId:'H-EXPLORER',filename:'estructurasPackage.h',mimeType:'text/x-chdr'});
    
    
      window.jstiming.load.tick('dt', '_dt');
    
    gviewApp.setProgress(80);

    
      
      window.jstiming.load.tick('_ct');
    
  </script>



<script type="text/javascript">
    function move_html_elements() {
      
      if (gviewApp) {
        
        gviewApp.sethm(true, false);
        var content = document.getElementById('gview-html-content');
        
        var stylesheets = content.getElementsByTagName('style');
        var head = document.getElementsByTagName('head')[0];
        while ( stylesheets.length > 0 ) {
           head.appendChild(stylesheets[stylesheets.length - 1]);
        }
        
        var pagePaneEl = document.getElementById('page-pane');
        pagePaneEl.appendChild(content);
      }
    }
    move_html_elements();
  </script>
<script type="text/javascript">
          window.jstiming.load.tick('ct', '_ct');
        </script>

<script type="text/javascript">
        
        gviewApp.setProgress(90);
        
        gviewApp.setDisplayData(
            {svUrl:'?pid\75explorer\46srcid\0750B--MFC48AFZiaVNVbVk5NjVrcWJwUm5ySzg1bTVvZ3Boc0Fv\46rel\75rar;r14;estructurasPackage.h\46docid\75d62ccecf2f4f7a8a186924c2929bcc5d%7Cbd703c0786817b33b8867147f51009aa\46chan\75EQAAAHzn5BzEAAbFBwF3olN7tKL5Yb%2Bz3E59gZTrCmdHGKFt\46a\75sv\46xt\75AC6rffAFFIHDvV1-sCJJZ0LCtKS_vyhMDQ:1400768121251',ulUrl:'?pid\75explorer\46srcid\0750B--MFC48AFZiaVNVbVk5NjVrcWJwUm5ySzg1bTVvZ3Boc0Fv\46rel\75rar;r14;estructurasPackage.h\46docid\75d62ccecf2f4f7a8a186924c2929bcc5d%7Cbd703c0786817b33b8867147f51009aa\46chan\75EQAAAHzn5BzEAAbFBwF3olN7tKL5Yb%2Bz3E59gZTrCmdHGKFt\46a\75v',svEna:true,pwdReq:false,biUrl:'?pid\75explorer\46srcid\0750B--MFC48AFZiaVNVbVk5NjVrcWJwUm5ySzg1bTVvZ3Boc0Fv\46rel\75rar;r14;estructurasPackage.h\46docid\75d62ccecf2f4f7a8a186924c2929bcc5d%7Cbd703c0786817b33b8867147f51009aa\46chan\75EQAAAHzn5BzEAAbFBwF3olN7tKL5Yb%2Bz3E59gZTrCmdHGKFt\46a\75bi',chanId:'EQAAAHzn5BzEAAbFBwF3olN7tKL5Yb+z3E59gZTrCmdHGKFt',docId:'d62ccecf2f4f7a8a186924c2929bcc5d|bd703c0786817b33b8867147f51009aa',gtUrl:'?pid\75explorer\46srcid\0750B--MFC48AFZiaVNVbVk5NjVrcWJwUm5ySzg1bTVvZ3Boc0Fv\46rel\75rar;r14;estructurasPackage.h\46docid\75d62ccecf2f4f7a8a186924c2929bcc5d%7Cbd703c0786817b33b8867147f51009aa\46chan\75EQAAAHzn5BzEAAbFBwF3olN7tKL5Yb%2Bz3E59gZTrCmdHGKFt\46a\75gt',dlUrl:'https://docs.google.com/uc?export\75download\46id\0750B--MFC48AFZiaVNVbVk5NjVrcWJwUm5ySzg1bTVvZ3Boc0Fv\46authuser\0750',ptUrl:'?pid\75explorer\46srcid\0750B--MFC48AFZiaVNVbVk5NjVrcWJwUm5ySzg1bTVvZ3Boc0Fv\46rel\75rar;r14;estructurasPackage.h\46docid\75d62ccecf2f4f7a8a186924c2929bcc5d%7Cbd703c0786817b33b8867147f51009aa\46chan\75EQAAAHzn5BzEAAbFBwF3olN7tKL5Yb%2Bz3E59gZTrCmdHGKFt\46a\75pt'});
        gviewApp.finalizeApp();
        
          window.jstiming.load.tick('prt');
        
      </script>

</body></html>