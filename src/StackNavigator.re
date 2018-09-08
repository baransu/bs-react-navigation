type navigatorConfig = {initialRouteName: option(string)};

type navigationPropsJs('screenProps, 'params) = {
  .
  "navigation": Navigation.t('params),
  "screenProps": 'screenProps,
  "navigationOptions": Js.Undefined.t(NavigationOptions.t),
};

let navigationOptions = NavigationOptions.toJs;

module Route = {
  [@bs.deriving abstract]
  type t('screenProps, 'params) = {
    screen:
      navigationPropsJs('screenProps, 'params) => ReasonReact.reactElement,
    path: Js.Undefined.t(string),
    navigationOptions: Js.Undefined.t(NavigationOptions.t),
  };

  type screen('params) =
    (~navigation: Navigation.t('params)) => ReasonReact.reactElement;

  let toJs = (~screen: screen('params), ~path=?, ~navigationOptions=?, ()) =>
    Js.Undefined.(
      t(
        ~screen=props => screen(~navigation=props##navigation),
        ~path=fromOption(path),
        ~navigationOptions=fromOption(navigationOptions),
      )
    );
};

let route = Route.toJs;

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