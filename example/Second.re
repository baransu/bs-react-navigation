open BsReactNative;

let component = ReasonReact.statelessComponent("Second");
let make = (~navigation, _) => {
  ...component,
  render: _ =>
    <SafeAreaView>
      <Button
        title="Go back"
        onPress={_ => Navigation.goBack(navigation, ())}
      />
    </SafeAreaView>,
};