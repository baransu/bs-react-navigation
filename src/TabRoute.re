type navigationPropsJs('screenProps, 'params, 'options) = {
  .
  "navigation": Navigation.t('params),
  "screenProps": 'screenProps,
  "navigationOptions": Js.Undefined.t('options),
};

[@bs.deriving abstract]
type t('screenProps, 'params, 'options) = {
  screen:
    navigationPropsJs('screenProps, 'params, 'options) =>
    ReasonReact.reactElement,
  path: Js.Undefined.t(string),
  navigationOptions: Js.Undefined.t('options),
};

type screen('screenProps, 'params) =
  (~navigation: Navigation.t('params), ~screenProps: 'screenProps) =>
  ReasonReact.reactElement;

let route =
    (
      ~screen: screen('params, 'screenProps),
      ~path=?,
      ~navigationOptions=?,
      (),
    ) =>
  Js.Undefined.(
    t(
      ~screen=
        props =>
          screen(
            ~navigation=props##navigation,
            ~screenProps=props##screenProps,
          ),
      ~path=fromOption(path),
      ~navigationOptions=fromOption(navigationOptions),
    )
  );