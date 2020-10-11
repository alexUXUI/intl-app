open Utils;

[@react.component]

let make = () => {

    <header className="toolbar">
        <span className="content-header">
            <h1>{s("Header")}</h1>
        </span>
        <ul>
            <li>
                {s("Utility One")}
            </li>
            <li>
                {s("Utility Two")}
            </li>
            <li>
                {s("Utility Three")}
            </li>
        </ul>
    </header>;
}