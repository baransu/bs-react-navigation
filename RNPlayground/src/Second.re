open BsReactNative;
open BsReactNavigation;

let component = ReasonReact.statelessComponent("Second");
let make = (~navigation, _) => {
  ...component,
  render: _ =>
    <View>
      <Text> {ReasonReact.string("second")} </Text>
      <Button
        title="Go to second"
        onPress={_ => Navigation.goBack(navigation, ())}
      />
    </View>,
};