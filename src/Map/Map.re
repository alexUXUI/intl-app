open Utils;
open Webapi.Dom;
open Document;
open Belt;
open MapboxGL;
open Env;

[@bs.val] external document: Js.t({..}) = "document";

// set accessToken from environment variable
let accessToken: string = mapboxKey;
setAccessToken(mapboxGL, accessToken);

[@react.component]
let make = () => {
  let mapRef = React.useRef(Js.Nullable.null);

  React.useEffect(() => {
    mapRef
    ->React.Ref.current
    ->Js.Nullable.toOption
    ->Option.map(myRef => {
        let map_options = {
          "container": mapRef.current,
          "style": "mapbox://styles/mapbox/streets-v9",
          "center": LngLat.make(~lng=-74.50, ~lat=40.),
          "zoom": 9.,
        };

        // create map
        let map = MapGL.make(map_options);

        // MapGL center getter
        let center = MapGL.getCenter(map);

        // LngLat getters
        let lng = LngLat.lng(center);
        let lat = LngLat.lat(center);

        // LngLat constructor
        let center = LngLat.make(~lng=-74.50, ~lat=40.);

        let onLoad = () => {
          let source = {
            "type": "vector",
            "url": "mapbox://mapbox.mapbox-terrain-v2",
          };

          let layer = {
            "id": "terrain-data",
            "type": "line",
            "source": "contour",
            "source-layer": "contour",
            "layout": {
              "line-join": "round",
              "line-cap": "round",
            },
            "paint": {
              "line-color": "#ff69b4",
              "line-width": 1,
            },
          };

          MapGL.setCenter(map, center);
          MapGL.addSource(map, "contour", source);
          MapGL.addLayer(map, layer);

          ();
        };
        MapGL.on(map, "load", onLoad);
      })
    ->ignore;
    None;
  });

  <div>
    <h4> {s("Map")} </h4>
    <div ref={ReactDOM.Ref.domRef(mapRef)} className="map" />
  </div>;
};
