'use strict';

var React = require("react");
var Utils$IntlApp = require("../Utils.bs.js");

function ToolBar(Props) {
  return React.createElement("header", {
              className: "toolbar"
            }, React.createElement("span", {
                  className: "content-header"
                }, React.createElement("h1", undefined, Utils$IntlApp.s("Header"))), React.createElement("ul", undefined, React.createElement("li", undefined, Utils$IntlApp.s("Utility One")), React.createElement("li", undefined, Utils$IntlApp.s("Utility Two")), React.createElement("li", undefined, Utils$IntlApp.s("Utility Three"))));
}

var make = ToolBar;

exports.make = make;
/* react Not a pure module */
