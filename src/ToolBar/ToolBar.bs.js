'use strict';

var React = require("react");
var Utils$Earth = require("../Utils.bs.js");

function ToolBar(Props) {
  return React.createElement("header", {
              className: "toolbar"
            }, React.createElement("span", {
                  className: "content-header"
                }, React.createElement("h1", undefined, Utils$Earth.s("Header"))), React.createElement("ul", undefined, React.createElement("li", undefined, Utils$Earth.s("Utility One")), React.createElement("li", undefined, Utils$Earth.s("Utility Two")), React.createElement("li", undefined, Utils$Earth.s("Utility Three"))));
}

var make = ToolBar;

exports.make = make;
/* react Not a pure module */
