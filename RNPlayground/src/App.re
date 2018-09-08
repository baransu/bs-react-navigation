open BsReactNative;
open BsReactNavigation;

module Config = {
  open StackNavigator;
  type screenProps;
  type params = {. "a": int};

  let routes: routes(screenProps, params) = [
    (
      "First",
      route(
        ~screen=(~navigation) => <First navigation />,
        ~navigationOptions=navigationOptions(~title="First", ()),
        (),
      ),
    ),
    (
      "Second",
      route(
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
  render: _self => <Navigation screenProps=0 />,
  /* <SafeAreaView style=styles##app>
       <Text> {ReasonReact.string("hello world everyomne!")} </Text>
     </SafeAreaView> */
};

let reactClass =
  ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));