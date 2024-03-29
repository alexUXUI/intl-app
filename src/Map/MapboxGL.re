type t;

[@bs.module] external mapboxGL: t = "mapbox-gl";
[@bs.set] external setAccessToken: (t, string) => unit = "accessToken";

type source = {
  .
  "type": string,
  "url": string,
};

type layer = {
  .
  "id": string,
  "type": string,
  "layout": {
    .
    "line-cap": string,
    "line-join": string,
  },
  "paint": {
    .
    "line-color": string,
    "line-width": int,
  },
  "source": string,
  "source-layer": string,
};

// type lngLat = {
//   lat: float,
//   lng: float,
// };

// type mapData = {lngLat: lngLat};

module LngLat = {
  type t;

  [@bs.module "mapbox-gl"] [@bs.new]
  external make: (~lng: float, ~lat: float) => t = "LngLat";

  [@bs.get] external lng: t => float;
  [@bs.get] external lat: t => float;
};

module MapGL = {
  type t;

  [@bs.send] external getCenter: t => LngLat.t;
  [@bs.send] external setCenter: (t, LngLat.t) => unit;
  [@bs.send] external getZoom: t => float;
  [@bs.send] external setZoom: (t, float) => t;

  [@bs.send] external on: (t, string, 'b => unit) => unit;
  [@bs.send] external off: (t, string, unit => unit) => t;
  [@bs.send] external once: (t, string, unit => unit) => t;

  [@bs.send] external addSource: (t, string, source) => unit;
  [@bs.send] external getSource: (t, string) => source;

  [@bs.send] external addLayer: (t, layer) => unit;
  [@bs.send] external getLayer: (t, string) => layer;

  type map_options('a) = {
    .
    "container": Js.Nullable.t('a),
    "style": string,
    "center": LngLat.t,
    "zoom": float,
  };

  [@bs.module "mapbox-gl"] [@bs.new]
  external make: map_options('a) => t = "Map";
};
