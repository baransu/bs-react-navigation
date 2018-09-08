type navigatorConfig = {initialRouteName: option(string)};

let navigationOptions = NavigationOptions.toJs;

type routes('screenProps, 'params) =
  list((string, Route.t('screenProps, 'params)));

[@bs.module "react-navigation"]
external createStackNavigator:
  (
    Js.Dict.t(Route.t('screenProps, 'params)),
    Js.Undefined.t(navigatorConfig)
  ) =>
  ReasonReact.reactClass =
  "createStackNavigator";

module type Config = {
  type screenProps;
  type params;
  let routes: routes(screenProps, params);
  let navigationConfig: option(navigatorConfig);
};

module Create = (Config: Config) => {
  let reactClass =
    createStackNavigator(
      Config.routes |> Js.Dict.fromList,
      Js.Undefined.fromOption(Config.navigationConfig),
    );

  let make = (~screenProps, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={"screenProps": screenProps},
      children,
    );
};