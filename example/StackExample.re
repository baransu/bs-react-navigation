module Config = {
  open StackNavigator;

  type screenProps;
  type params = [ | `Noop | `Input(string)];

  let routes: routes(screenProps, params) = [
    (
      Routes.toString(`First),
      StackRoute.route(
        ~screen=
          (~navigation, ~params, ~screenProps as _) =>
            <First navigation params />,
        ~navigationOptions=navigationOptions(~title="First", ()),
        (),
      ),
    ),
    (
      Routes.toString(`Second),
      StackRoute.route(
        ~screen=
          (~navigation, ~params, ~screenProps as _) =>
            <Second navigation params />,
        ~navigationOptions=navigationOptions(~title="Second", ()),
        (),
      ),
    ),
  ];

  let navigatorConfig = navigatorConfig(~initialParams=`Noop, ());
};

include StackNavigator.Create(Config);