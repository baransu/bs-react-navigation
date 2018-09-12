module Config = {
  open StackNavigator;
  type screenProps;
  type params;

  let routes: routes(screenProps, params) = [
    (
      "First",
      Route.route(
        ~screen=(~navigation, ~screenProps as _) => <First navigation />,
        ~navigationOptions=navigationOptions(~title="First", ()),
        (),
      ),
    ),
    (
      "Second",
      Route.route(
        ~screen=(~navigation, ~screenProps as _) => <Second navigation />,
        ~navigationOptions=navigationOptions(~title="Second", ()),
        (),
      ),
    ),
  ];
  let navigatorConfig = None;
};

include StackNavigator.Create(Config);