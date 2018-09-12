open BsReactNative;
open BsReactNavigation;

let component = ReasonReact.statelessComponent("Second");
let make = (~navigation, _) => {
  ...component,
  render: _ =>
    <View>
      <Button
        title="Go back"
        onPress={_ => Navigation.goBack(navigation, ())}
      />
    </View>,
};