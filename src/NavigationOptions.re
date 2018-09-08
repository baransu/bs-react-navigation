open BsReactNative;

[@bs.deriving abstract]
type t = {
  title: Js.Undefined.t(string),
  /* header: option [ | `custom (headerProps => ReasonReact.reactElement) | `notVisible], */
  headerTitle: Js.Undefined.t(ReasonReact.reactElement),
  headerTitleStyle: Js.Undefined.t(Style.t),
  headerTintColor: Js.Undefined.t(string),
  headerBackTitle: Js.Undefined.t(string),
  headerTruncatedBackTitle: Js.Undefined.t(string),
  headerLeft: Js.Undefined.t(ReasonReact.reactElement),
  headerBackTitleStyle: Js.Undefined.t(Style.t),
  headerPressColorAndroid: Js.Undefined.t(string),
  headerRight: Js.Undefined.t(ReasonReact.reactElement),
  headerStyle: Js.Undefined.t(Style.t),
  gesturesEnabled: Js.Undefined.t(bool),
};

let toJs =
    (
      ~title=?,
      ~headerTitle=?,
      ~headerTitleStyle=?,
      ~headerTintColor=?,
      ~headerBackTitle=?,
      ~headerTruncatedBackTitle=?,
      ~headerLeft=?,
      ~headerBackTitleStyle=?,
      ~headerPressColorAndroid=?,
      ~headerRight=?,
      ~headerStyle=?,
      ~gesturesEnabled=?,
      (),
    ) =>
  Js.Undefined.(
    t(
      ~title=fromOption(title),
      /* header: option [ | `custom (headerProps => ReasonReact.reactElement) | `notVisible], */
      ~headerTitle=fromOption(headerTitle),
      ~headerTitleStyle=fromOption(headerTitleStyle),
      ~headerTintColor=fromOption(headerTintColor),
      ~headerBackTitle=fromOption(headerBackTitle),
      ~headerTruncatedBackTitle=fromOption(headerTruncatedBackTitle),
      ~headerLeft=fromOption(headerLeft),
      ~headerBackTitleStyle=fromOption(headerBackTitleStyle),
      ~headerPressColorAndroid=fromOption(headerPressColorAndroid),
      ~headerRight=fromOption(headerRight),
      ~headerStyle=fromOption(headerStyle),
      ~gesturesEnabled=fromOption(gesturesEnabled),
    )
  );