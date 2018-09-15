open BsReactNative;

let component = ReasonReact.statelessComponent("Second");
let make = (~navigation, ~params, _) => {
  ...component,
  render: _ => {
    let input =
      switch (params) {
      | `Input(input) => input
      | _ => "empty"
      };

    <SafeAreaView>
      <Text> {ReasonReact.string("Params payload: " ++ input)} </Text>
      <Button
        title="Go back"
        onPress={_ => Navigation.goBack(navigation, ())}
      />
    </SafeAreaView>;
  },
};