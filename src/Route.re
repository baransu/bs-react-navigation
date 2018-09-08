type navigationPropsJs('screenProps, 'params) = {
  .
  "navigation": Navigation.t('params),
  "screenProps": 'screenProps,
  "navigationOptions": Js.Undefined.t(NavigationOptions.t),
};

[@bs.deriving abstract]
type t('screenProps, 'params) = {
  screen:
    navigationPropsJs('screenProps, 'params) => ReasonReact.reactElement,
  path: Js.Undefined.t(string),
  navigationOptions: Js.Undefined.t(NavigationOptions.t),
};

type screen('params) =
  (~navigation: Navigation.t('params)) => ReasonReact.reactElement;

let route = (~screen: screen('params), ~path=?, ~navigationOptions=?, ()) =>
  Js.Undefined.(
    t(
      ~screen=props => screen(~navigation=props##navigation),
      ~path=fromOption(path),
      ~navigationOptions=fromOption(navigationOptions),
    )
  );