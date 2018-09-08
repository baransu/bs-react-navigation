type t('params);

type state('params) = {
  routeName: string,
  key: string,
  params: Js.t('params),
  path: option(string),
  index: option(int),
  /*routes: option (array (state {.}))*/
};

type stateJs('params) = {
  .
  "key": string,
  "routeName": string,
  "path": Js.Undefined.t(string),
  "params": Js.Undefined.t(Js.t('params)),
  "index": Js.Undefined.t(int),
  /*routes : Js.Undefined.t (array (stateJs {.}))*/
};

[@bs.send] external getState: t('params) => stateJs('params) = "state";

let state = t => {
  let js = getState(t);
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
  (t('params), string, Js.Undefined.t(Js.t('params))) /* TODO action => */ =>
  unit =
  "navigate";

let navigate = (t, ~routeName, ~params=? /* TODO ~action=? */, ()) =>
  navigate_(t, routeName, Js.Undefined.fromOption(params));

external setParams: (t('params), Js.t('params)) => unit = "";

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