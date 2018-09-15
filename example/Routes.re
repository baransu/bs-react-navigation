[@bs.deriving jsConverter]
type route = [ | `First | `Second];

let toString = routeToJs;