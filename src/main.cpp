#include <iostream>

#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/screen/screen.hpp"
#include "ftxui/screen/string.hpp"

int main(int argc, char* argv[])
{
    using namespace ftxui;

    auto summary = [&] {
    auto content = vbox({
        hbox({text(L"- done:   "), text(L"3") | bold}) | color(Color::Green),
        hbox({text(L"- active: "), text(L"2") | bold}) | color(Color::RedLight),
        hbox({text(L"- queue:  "), text(L"9") | bold}) | color(Color::Red),
    });
    return window(text(L" Summary "), content);
  };

  auto document =  //
      vbox({
          hbox({
              summary(),
              summary(),
              summary() | flex,
          }),
          summary(),
          summary(),
      });

  // Limit the size of the document to 80 char.
  document = document | size(WIDTH, LESS_THAN, 80);

//   auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
  auto screen = ScreenInteractive::Fullscreen();
//   Render(screen, document);

    // std::cout << screen.ToString() << std::endl;

    auto main_renderer = Renderer([&]{ return document; });

    screen.Loop(main_renderer);

    return 0;
}
