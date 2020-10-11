'use strict';

var React = require("react");
var Utils$IntlApp = require("../Utils.bs.js");

function Nav(Props) {
  return React.createElement("nav", {
              className: "nav--side"
            }, React.createElement("span", {
                  className: "nav-header"
                }, React.createElement("h1", undefined, Utils$IntlApp.s("App"))), React.createElement("ul", {
                  className: "nav-links"
                }, React.createElement("li", {
                      className: "nav-link"
                    }, Utils$IntlApp.s("Home"))));
}

var make = Nav;

exports.make = make;
/* react Not a pure module */
