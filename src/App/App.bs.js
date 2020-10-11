'use strict';

var React = require("react");
var Nav$IntlApp = require("../Nav/Nav.bs.js");
var Utils$IntlApp = require("../Utils.bs.js");
var ToolBar$IntlApp = require("../ToolBar/ToolBar.bs.js");

function App(Props) {
  return React.createElement("main", undefined, React.createElement(Nav$IntlApp.make, {}), React.createElement("section", {
                  className: "content"
                }, React.createElement(ToolBar$IntlApp.make, {}), React.createElement("section", {
                      className: "feature-module"
                    }, React.createElement("h3", undefined, Utils$IntlApp.s("Feature Module")))));
}

var make = App;

exports.make = make;
/* react Not a pure module */
