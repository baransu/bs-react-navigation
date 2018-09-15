open BsReactNative;

type action = string;

type state = string;

let styles =
  StyleSheet.create(
    Style.{
      "input":
        style([
          height(Pt(50.)),
          paddingHorizontal(Pt(4.)),
          paddingVertical(Pt(4.)),
          backgroundColor(String("#fff")),
        ]),
      "container":
        style([
          flex(1.),
          paddingHorizontal(Pt(16.)),
          paddingVertical(Pt(16.)),
        ]),
    },
  );

let navigateToSecond = (state, nav) =>
  NavigationAction.navigate(nav, `Second, `Input(state));

let component = ReasonReact.reducerComponent("First");
let make = (~navigation, ~params, _) => {
  ...component,
  initialState: () => "",
  reducer: (input, _) => ReasonReact.Update(input),
  render: self => {
    let input =
      switch (params) {
      | `Input(input) => input
      | _ => "empty"
      };

    <SafeAreaView style=styles##container>
      <TextInput
        placeholder="Type..."
        style=styles##input
        value={self.state}
        onChangeText={value => self.send(value)}
      />
      <Text> {ReasonReact.string("Params payload: " ++ input)} </Text>
      <Button
        title="Go to second"
        onPress={_ => navigateToSecond(self.state, navigation)}
      />
    </SafeAreaView>;
  },
};