open BsReactNative;

let styles =
  StyleSheet.create(
    Style.{"app": style([flex(1.0), backgroundColor(String("#F5F5F6"))])},
  );

let component = ReasonReact.statelessComponent("ReasonDemo");
let make = _children => {
  ...component,
  render: _self =>
    /* <BottomTabExample screenProps=None />*/
    <StackExample screenProps=None />,
};

let reactClass =
  ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));