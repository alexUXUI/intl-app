open Utils;

[@react.component]
let make = () => {
    <main>
        <Nav />
        <section className="content">
            <ToolBar />
            <section className="feature-module">
                <h3>{s("Feature Module")}</h3>
            </section>
        </section>
    </main>;
}
