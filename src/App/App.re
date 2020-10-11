[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";

open Utils;
open Env;
open Map;
open MapboxGL;

type weatherData = {
    lat: float,
    lon: float,
    timezone: string,
    timezone_offset: int,
}

type weatherState = 
    | Loading
    | Error
    | Success(weatherData);

[@react.component]
let make = () => {

    let (weather, setWeather) = React.useState(() => Loading);

    React.useEffect0(() => {

        let key = weatherKey;
        let url = {j|https://api.openweathermap.org/data/2.5/onecall?lat=33.441792&lon=-94.037689&exclude=hourly,daily&appid=$key|j};

        Js.Promise.(
            fetch(url)
            |> then_(response => response##json())
            |> then_(jsonResponse => {
                    setWeather(_previousState => Success({ 
                        lat: jsonResponse##lat, 
                        lon: jsonResponse##lon,
                        timezone: jsonResponse##timezone,
                        timezone_offset: jsonResponse##timezone_offset,
                    }))
                    Js.Promise.resolve();
                })
            |> catch(_err => {
                setWeather(_previousState => Error);
                Js.Promise.resolve();
            })
            |> ignore
        );

        None;
    });

    <main>
        <Nav />
        <section className="content">
            <ToolBar />
            <section className="feature-module">
                <Map />

                <h3>{s("Feature Module")}</h3>
                <div>
                    {
                        switch weather {
                            | Loading => s("Loading...")
                            | Error => s("failed to load weather data")
                            | Success(data) => s("Got weather data")
                        };
                    }
                </div>
            </section>
        </section>
    </main>;
};
