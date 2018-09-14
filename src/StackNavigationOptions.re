open BsReactNative;

[@bs.deriving abstract]
type t = {
  title: Js.Undefined.t(string),
  /* TODO: header: option [ | `custom (headerProps => ReasonReact.reactElement) | `notVisible], */
  headerTitle: Js.Undefined.t(ReasonReact.reactElement),
  headerTitleAllowFontScaling: Js.Undefined.t(bool),
  /* TODO: headerBackImage */
  headerBackTitle: Js.Undefined.t(string), /* TODO: add support for null */
  headerTruncatedBackTitle: Js.Undefined.t(string),
  headerRight: Js.Undefined.t(ReasonReact.reactElement), /* TODO: handle passed props like onPress etc */
  headerLeft: Js.Undefined.t(ReasonReact.reactElement),
  /* TODO: headerForceInset */
  headerTitleStyle: Js.Undefined.t(Style.t),
  headerBackTitleStyle: Js.Undefined.t(Style.t),
  headerLeftContainerStyle: Js.Undefined.t(Style.t),
  headerRightContainerStyle: Js.Undefined.t(Style.t),
  headerTitleContainerStyle: Js.Undefined.t(Style.t),
  headerTintColor: Js.Undefined.t(string),
  headerPressColorAndroid: Js.Undefined.t(string),
  headerTransparent: Js.Undefined.t(bool),
  headerBackground: Js.Undefined.t(ReasonReact.reactElement),
  gesturesEnabled: Js.Undefined.t(bool),
  /* TODO: gestureResponseDistance */
  /* TODO: gestureDirection */
};

let toJs =
    (
      ~title=?,
      ~headerTitle=?,
      ~headerTitleAllowFontScaling=?,
      ~headerBackTitle=?,
      ~headerTruncatedBackTitle=?,
      ~headerRight=?,
      ~headerLeft=?,
      ~headerTitleStyle=?,
      ~headerBackTitleStyle=?,
      ~headerLeftContainerStyle=?,
      ~headerRightContainerStyle=?,
      ~headerTitleContainerStyle=?,
      ~headerTintColor=?,
      ~headerPressColorAndroid=?,
      ~headerTransparent=?,
      ~headerBackground=?,
      ~gesturesEnabled=?,
      (),
    ) =>
  Js.Undefined.(
    t(
      ~title=fromOption(title),
      ~headerTitle=fromOption(headerTitle),
      ~headerTitleAllowFontScaling=fromOption(headerTitleAllowFontScaling),
      ~headerBackTitle=fromOption(headerBackTitle),
      ~headerTruncatedBackTitle=fromOption(headerTruncatedBackTitle),
      ~headerRight=fromOption(headerRight),
      ~headerLeft=fromOption(headerLeft),
      ~headerTitleStyle=fromOption(headerTitleStyle),
      ~headerBackTitleStyle=fromOption(headerBackTitleStyle),
      ~headerRightContainerStyle=fromOption(headerRightContainerStyle),
      ~headerLeftContainerStyle=fromOption(headerLeftContainerStyle),
      ~headerTitleContainerStyle=fromOption(headerTitleContainerStyle),
      ~headerTintColor=fromOption(headerTintColor),
      ~headerPressColorAndroid=fromOption(headerPressColorAndroid),
      ~headerTransparent=fromOption(headerTransparent),
      ~headerBackground=fromOption(headerBackground),
      ~gesturesEnabled=fromOption(gesturesEnabled),
    )
  );