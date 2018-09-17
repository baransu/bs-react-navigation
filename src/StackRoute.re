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
  (~navigation: Navigation.t('params), ~params: 'params) =>
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
        props => {
          let navigation = props##navigation;
          let state = Navigation.stackState(navigation);
          screen(~navigation, ~params=state.params);
        },
      ~path=fromOption(path),
      ~navigationOptions=fromOption(navigationOptions),
    )
  );