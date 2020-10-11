'use strict';

var React = require("react");
var ReactDom = require("react-dom");
var App$IntlApp = require("./App/App.bs.js");

ReactDom.render(React.createElement(App$IntlApp.make, {}), document.getElementById("root"));

/*  Not a pure module */
