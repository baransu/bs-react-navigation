open BsReactNative;

type action = string;

type state = string;

let component = ReasonReact.reducerComponent("First");
let make = (~navigation, _) => {
  ...component,
  initialState: () => "",
  reducer: (input, _) => ReasonReact.Update(input),
  render: self =>
    <SafeAreaView
      style=Style.(
        style([
          flex(1.),
          paddingHorizontal(Pt(16.)),
          paddingVertical(Pt(16.)),
        ])
      )>
      <TextInput
        placeholder="Type..."
        style=Style.(
          style([
            height(Pt(50.)),
            paddingHorizontal(Pt(4.)),
            paddingVertical(Pt(4.)),
            backgroundColor(String("#fff")),
          ])
        )
        value={self.state}
        onChangeText={value => self.send(value)}
      />
      <Button
        title="Go to second"
        onPress={
          _ =>
            Navigation.navigate(
              navigation,
              ~routeName="Second",
              ~params={"input": self.state},
              (),
            )
        }
      />
    </SafeAreaView>,
};