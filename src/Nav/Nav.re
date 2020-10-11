open Utils;

[@react.component]
let make = () => {
    <nav className="nav--side">
        <span className="nav-header"><h1>{s("App")}</h1></span>
        <ul className="nav-links">
            <li className="nav-link">
                { s( "Home" ) }
            </li>
        </ul>
    </nav>
}