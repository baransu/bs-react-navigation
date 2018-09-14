type stateJs('params) = {
  .
  "key": string,
  "routeName": string,
  "path": Js.Undefined.t(string),
  "params": Js.Undefined.t('params),
  "index": Js.Undefined.t(int),
  /*routes : Js.Undefined.t (array (stateJs {.}))*/
};

type t('params) = {. "state": stateJs('params)};

type state('params) = {
  routeName: string,
  key: string,
  params: 'params,
  path: option(string),
  index: option(int),
  /*routes: option (array (state {.}))*/
};

let state = t => {
  let js = t##state;
  let key = js##key;
  let routeName = js##routeName;
  let params =
    js##params
    |> Js.Undefined.toOption
    |> Belt.Option.getWithDefault(_, Js.Obj.empty());

  let path = Js.Undefined.toOption(js##path);
  let index = Js.Undefined.toOption(js##index);
  /*let routes = Js.Undefined.to_opt js##routes |> NavUtils.option_map (Array.map fromJs);*/
  {key, routeName, params, path, index};
};

[@bs.send]
external navigate_:
  (t('params), string, Js.Undefined.t('params)) /* TODO action => */ => unit =
  "navigate";

let navigate = (t, ~routeName, ~params=? /* TODO ~action=? */, ()) =>
  navigate_(t, routeName, Js.Undefined.fromOption(params));

external setParams: (t('params), 'params) => unit = "";

[@bs.send]
external goBack_: (t('params), Js.Null_undefined.t(string)) => unit =
  "goBack";

type from = [ | `routeKey(string) | `anywhere];

let goBack = (t, ~from=?, ()) =>
  switch (from) {
  | Some(`routeKey(routeKey)) =>
    goBack_(t, Js.Null_undefined.return(routeKey))
  | Some(`anywhere) => goBack_(t, Js.Null_undefined.null)
  | _ => goBack_(t, Js.Null_undefined.undefined)
  };

[@bs.send]
external dispatch: (t('params), NavigationActions.t('params)) => unit = "";