'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Env$Earth = require("../Env.bs.js");
var Map$Earth = require("../Map/Map.bs.js");
var Nav$Earth = require("../Nav/Nav.bs.js");
var Utils$Earth = require("../Utils.bs.js");
var ToolBar$Earth = require("../ToolBar/ToolBar.bs.js");

function App(Props) {
  var match = React.useState(function () {
        return /* Loading */0;
      });
  var setWeather = match[1];
  var weather = match[0];
  React.useEffect((function () {
          var url = "https://api.openweathermap.org/data/2.5/onecall?lat=33.441792&lon=-94.037689&exclude=hourly,daily&appid=" + Env$Earth.weatherKey;
          fetch(url).then(function (response) {
                    return response.json();
                  }).then(function (jsonResponse) {
                  Curry._1(setWeather, (function (_previousState) {
                          return /* Success */{
                                  _0: {
                                    lat: jsonResponse.lat,
                                    lon: jsonResponse.lon,
                                    timezone: jsonResponse.timezone,
                                    timezone_offset: jsonResponse.timezone_offset
                                  }
                                };
                        }));
                  return Promise.resolve(undefined);
                }).catch(function (_err) {
                Curry._1(setWeather, (function (_previousState) {
                        return /* Error */1;
                      }));
                return Promise.resolve(undefined);
              });
          
        }), []);
  return React.createElement("main", undefined, React.createElement(Nav$Earth.make, {}), React.createElement("section", {
                  className: "content"
                }, React.createElement(ToolBar$Earth.make, {}), React.createElement("section", {
                      className: "feature-module"
                    }, React.createElement(Map$Earth.make, {}), React.createElement("h3", undefined, Utils$Earth.s("Feature Module")), React.createElement("div", undefined, typeof weather === "number" ? (
                            weather !== 0 ? Utils$Earth.s("failed to load weather data") : Utils$Earth.s("Loading...")
                          ) : Utils$Earth.s("Got weather data")))));
}

var make = App;

exports.make = make;
/* react Not a pure module */
