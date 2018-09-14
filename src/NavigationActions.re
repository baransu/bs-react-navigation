type t('params);

[@bs.module "react-navigation"] [@bs.scope "NavigationActions"]
external navigate_:
  {
    .
    "routeName": string,
    "params": Js.Undefined.t('params),
    "action": Js.Undefined.t(t('params)),
  } =>
  t('params) =
  "navigate";

let navigate =
    (
      ~routeName: string,
      ~params: option('params)=?,
      ~action: option(t('params))=?,
      (),
    )
    : t('params) =>
  navigate_({
    "routeName": routeName,
    "params": Js.Undefined.fromOption(params),
    "action": Js.Undefined.fromOption(action),
  });

[@bs.module "react-navigation"] [@bs.scope "NavigationActions"]
external reset_:
  {
    .
    "index": int,
    "actions": Js.Undefined.t(array(t({.}))),
  } =>
  t('params) =
  "reset";

let reset =
    (~index: int, ~actions: option(list(t('params)))=?, ()): t('params) =>
  reset_({
    "index": index,
    "actions":
      actions |> Belt.Option.map(_, Array.of_list) |> Js.Undefined.fromOption,
  });

[@bs.module "react-navigation"] [@bs.scope "NavigationActions"]
external back_: {. "key": Js.Null.t(string)} => t('params) = "back";

let back = (~key=?, ()) =>
  switch (key) {
  | Some(key) => back_({"key": Js.Null.return(key)})
  | None => back_({"key": Js.Null.empty})
  };

[@bs.module "react-navigation"] [@bs.scope "NavigationActions"]
external setParams_:
  {
    .
    "params": Js.Dict.t(string),
    "key": string,
  } =>
  t('params) =
  "setParams";

let setParams = (~params, ~key) =>
  setParams_({"params": params, "key": key});

[@bs.scope "NavigationActions"] [@bs.module "react-navigation"]
external init_: {. "params": Js.Dict.t(string)} => t('params) = "init";

let init = (~params) => init_({"params": params});