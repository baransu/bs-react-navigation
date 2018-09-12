open BsReactNative;

let component = ReasonReact.statelessComponent("First");
let make = (~navigation, _) => {
  ...component,
  render: _ =>
    <SafeAreaView>
      <Button
        title="Go to second"
        onPress={
          _ => Navigation.navigate(navigation, ~routeName="Second", ())
        }
      />
    </SafeAreaView>,
};