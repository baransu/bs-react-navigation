[@bs.deriving abstract]
type t = {
  title: Js.Undefined.t(string),
  tabBarVisible: Js.Undefined.t(bool),
  /* TODO: add support for function with { focusedL: boolean, tintColor: string } */
  tabBarIcon: Js.Undefined.t(ReasonReact.reactElement),
  /* TODO: add support for function with { focusedL: boolean, tintColor: string } */
  tabBarLabel: Js.Undefined.t(ReasonReact.reactElement),
  /* TODO: tabBarButtonComponent which accepts onPress event */
  tabBarAccessibilityLabel: Js.Undefined.t(string),
  tabBarTestID: Js.Undefined.t(string),
  /* TODO: tabBarOnPress */
};

let toJs =
    (
      ~title=?,
      ~tabBarVisible=?,
      ~tabBarIcon=?,
      ~tabBarLabel=?,
      ~tabBarAccessibilityLabel=?,
      ~tabBarTestID=?,
      (),
    ) =>
  Js.Undefined.(
    t(
      ~title=fromOption(title),
      ~tabBarVisible=fromOption(tabBarVisible),
      ~tabBarIcon=fromOption(tabBarIcon),
      ~tabBarLabel=fromOption(tabBarLabel),
      ~tabBarAccessibilityLabel=fromOption(tabBarAccessibilityLabel),
      ~tabBarTestID=fromOption(tabBarTestID),
    )
  );