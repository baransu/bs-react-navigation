open BsReactNative;

let component = ReasonReact.statelessComponent("Second");
let make = (~navigation, _) => {
  ...component,
  render: _ => {
    let input = Navigation.state(navigation).params##input;

    <SafeAreaView>
      <Text> {ReasonReact.string("Payload first screen: " ++ input)} </Text>
      <Button
        title="Go back"
        onPress={_ => Navigation.goBack(navigation, ())}
      />
    </SafeAreaView>;
  },
};