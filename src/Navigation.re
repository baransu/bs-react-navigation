type stateJs('params) = {
  .
  "key": string,
  "routeName": string,
  "path": Js.Undefined.t(string),
  "params": {. "params": 'params},
  "index": Js.Undefined.t(int),
};

type t('params) = {. "state": stateJs('params)};

type state('params) = {
  routeName: string,
  key: string,
  params: 'params,
  path: option(string),
  index: option(int),
};

let state = (t: t('params)) => {
  let js = t##state;
  let key = js##key;
  let routeName = js##routeName;
  let params = js##params##params;

  let path = Js.Undefined.toOption(js##path);
  let index = Js.Undefined.toOption(js##index);

  {key, routeName, params, path, index};
};

[@bs.send]
external navigate_: (t('params), string, {. "params": 'params}) => unit =
  "navigate";

let navigate = (t, ~routeName, ~params, ()) =>
  navigate_(t, routeName, {"params": params});

/* external setParams: (t('params), 'params) => unit = ""; */

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