#include "pch.h"
#include "MainWindow.xaml.h"

#include <Enigma.h>
#include <vector>
#include <random>

#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::J_Encrypter::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
    }

    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainWindow::GenKey(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        auto s = std::stoul(to_string(inpTxt().Text()));
        const char alphabet[26]{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
        ENIGMA_MACHINE mainEncrypt;
        ENIGMA_MACHINE backupEncrypt;
        std::vector<char> Vig;

        std::mt19937 rng(s);
        {
            std::uniform_int_distribution<std::mt19937::result_type> distRot(1, 5);
            mainEncrypt.SetRotorDataPath("Dependencies/RotorModules");

            // Rotor
            int temp1, temp2, temp3 = 0;
            temp1 = distRot(rng);
            temp2 = temp1;

            while (temp1 == temp2)
            {
                temp1 = distRot(rng);
            }

            temp3 = temp1;

            while (temp1 == temp2 || temp1 == temp3)
            {
                temp1 = distRot(rng);
            }

            mainEncrypt.GenNewRotorsModules(temp1, temp2, temp3);
        }

        // Vigenere
        std::uniform_int_distribution<std::mt19937::result_type> distAlph(1, 26);

        int tempVig = distAlph(rng) - 1;
        Vig.push_back(alphabet[tempVig]);

        while (distAlph(rng) != 9)
        {
            tempVig = distAlph(rng) - 1;
            Vig.push_back(alphabet[tempVig]);
        }

        // Pair

        std::array<Enigma::s_Pairs, 13> pairs;
        std::vector<int> letters;
        letters.push_back(distAlph(rng));
        while (letters.size() < 26)
        {
            bool check = false;
            int pairTemp = distAlph(rng);
            for (int i = 0; i < letters.size(); i++)
            {
                if (pairTemp == letters[i])
                {
                    check = true;
                    break;
                }
            }
            if (!check)
            {
                letters.push_back(pairTemp);
            }
        }

        for (int i = 0; i < 26; i += 2)
        {
            pairs[i / 2].pair1 = letters[i];
            pairs[i / 2].pair2 = letters[i + 1];
        }

        mainEncrypt.GenNewPairModule(pairs);
        pairs.empty();
        backupEncrypt = mainEncrypt;
    }
}
