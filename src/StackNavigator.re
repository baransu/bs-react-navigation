[@bs.deriving abstract]
type navigatorConfigT('params) = {
  /* TODO: add rest of StackNavigatorConfig */
  initialRouteName: Js.Undefined.t(string),
  initialRouteParams: {. "params": 'params},
};

let navigatorConfig = (~initialRouteName=?, ~initialParams, ()) =>
  Js.Undefined.(
    navigatorConfigT(
      ~initialRouteName=fromOption(initialRouteName),
      ~initialRouteParams={"params": initialParams},
    )
  );

let navigationOptions = StackNavigationOptions.toJs;

type route('screenProps, 'params) =
  StackRoute.t('screenProps, 'params, StackNavigationOptions.t);

type routes('screenProps, 'params) =
  list((string, route('screenProps, 'params)));

[@bs.module "react-navigation"]
external createStackNavigator:
  (Js.Dict.t(route('screenProps, 'params)), navigatorConfigT('params)) =>
  ReasonReact.reactClass =
  "createStackNavigator";

module type Config = {
  type screenProps;
  type params;
  let routes: routes(screenProps, params);
  let navigatorConfig: navigatorConfigT(params);
};

module Create = (Config: Config) => {
  let reactClass =
    createStackNavigator(
      Config.routes |> Js.Dict.fromList,
      Config.navigatorConfig,
    );

  let make = (~screenProps, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={"screenProps": screenProps},
      children,
    );
};