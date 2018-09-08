open BsReactNative;
open BsReactNavigation;

let component = ReasonReact.statelessComponent("First");
let make = (~navigation, _) => {
  ...component,
  render: _ =>
    <View>
      <Button
        title="Go to second"
        onPress={
          _ => Navigation.navigate(navigation, ~routeName="Second", ())
        }
      />
    </View>,
};