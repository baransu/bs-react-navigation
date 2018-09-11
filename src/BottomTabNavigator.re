type navigatorConfig = {
  /* TODO: add rest of BottomTabNavigatorConfig */
  initialRouteName: option(string),
};

let navigationOptions = BottomTabNavigationOptions.toJs;

type route('screenProps, 'params) =
  Route.t('screenProps, 'params, BottomTabNavigationOptions.t);

type routes('screenProps, 'params) =
  list((string, route('screenProps, 'params)));

[@bs.module "react-navigation"]
external createStackNavigator:
  (
    Js.Dict.t(route('screenProps, 'params)),
    Js.Undefined.t(navigatorConfig)
  ) =>
  ReasonReact.reactClass =
  "createBottomTabNavigator";

module type Config = {
  type screenProps;
  type params;
  let routes: routes(screenProps, params);
  let navigatorConfig: option(navigatorConfig);
};

module Create = (Config: Config) => {
  let reactClass =
    createStackNavigator(
      Config.routes |> Js.Dict.fromList,
      Js.Undefined.fromOption(Config.navigatorConfig),
    );

  let make = (~screenProps, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={"screenProps": screenProps},
      children,
    );
};