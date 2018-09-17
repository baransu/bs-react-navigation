[@bs.deriving abstract]
type navigatorConfigT('params) = {
  /* TODO: add rest of BottomTabNavigatorConfig */
  initialRouteName: Js.Undefined.t(string),
  initialRouteParams: {. "params": 'params},
};

let navigatorConfig = (~initialRouteName=?, ~initialParams, ()) =>
  navigatorConfigT(
    ~initialRouteName=Js.Undefined.fromOption(initialRouteName),
    ~initialRouteParams={"params": initialParams},
  );

let navigationOptions = BottomTabNavigationOptions.toJs;

type route('screenProps, 'params) =
  Route.t('screenProps, 'params, BottomTabNavigationOptions.t);

type routes('screenProps, 'params) =
  list((string, route('screenProps, 'params)));

[@bs.module "react-navigation"]
external createBottomTabNavigator:
  (Js.Dict.t(route('screenProps, 'params)), navigatorConfigT('params)) =>
  ReasonReact.reactClass =
  "createBottomTabNavigator";

module type Config = {
  type screenProps;
  type params;
  let routes: routes(screenProps, params);
  let navigatorConfig: navigatorConfigT(params);
};

module Create = (Config: Config) => {
  let reactClass =
    createBottomTabNavigator(
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