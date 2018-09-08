open BsReactNative;
open BsReactNavigation;

module Config = {
  open StackNavigator;
  type screenProps;
  type params;

  let routes: routes(screenProps, params) = [
    (
      "First",
      Route.route(
        ~screen=(~navigation) => <First navigation />,
        ~navigationOptions=navigationOptions(~title="First", ()),
        (),
      ),
    ),
    (
      "Second",
      Route.route(
        ~screen=(~navigation) => <Second navigation />,
        ~navigationOptions=navigationOptions(~title="Second", ()),
        (),
      ),
    ),
  ];
  let navigationConfig = None;
};

module Navigation = StackNavigator.Create(Config);

let styles =
  StyleSheet.create(
    Style.{"app": style([flex(1.0), backgroundColor(String("#F5F5F6"))])},
  );

let component = ReasonReact.statelessComponent("RNPlayground");
let make = _children => {
  ...component,
  render: _self => <Navigation screenProps=None />,
};

let reactClass =
  ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));