// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210806.1

#pragma once
#ifndef WINRT_Microsoft_UI_Xaml_Hosting_H
#define WINRT_Microsoft_UI_Xaml_Hosting_H
#include "winrt/base.h"
static_assert(winrt::check_version(CPPWINRT_VERSION, "2.0.210806.1"), "Mismatched C++/WinRT headers.");
#define CPPWINRT_VERSION "2.0.210806.1"
#include "winrt/Microsoft.UI.Xaml.h"
#include "winrt/impl/Microsoft.UI.Composition.2.h"
#include "winrt/impl/Microsoft.UI.Xaml.2.h"
#include "winrt/impl/Microsoft.UI.Xaml.Controls.2.h"
#include "winrt/impl/Microsoft.UI.Xaml.Hosting.2.h"
namespace winrt::impl
{
    template <typename D> WINRT_IMPL_AUTO(winrt::Microsoft::UI::Composition::Visual) consume_Microsoft_UI_Xaml_Hosting_IElementCompositionPreviewStatics<D>::GetElementVisual(winrt::Microsoft::UI::Xaml::UIElement const& element) const
    {
        void* result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Microsoft::UI::Xaml::Hosting::IElementCompositionPreviewStatics)->GetElementVisual(*(void**)(&element), &result));
        return winrt::Microsoft::UI::Composition::Visual{ result, take_ownership_from_abi };
    }
    template <typename D> WINRT_IMPL_AUTO(winrt::Microsoft::UI::Composition::Visual) consume_Microsoft_UI_Xaml_Hosting_IElementCompositionPreviewStatics<D>::GetElementChildVisual(winrt::Microsoft::UI::Xaml::UIElement const& element) const
    {
        void* result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Microsoft::UI::Xaml::Hosting::IElementCompositionPreviewStatics)->GetElementChildVisual(*(void**)(&element), &result));
        return winrt::Microsoft::UI::Composition::Visual{ result, take_ownership_from_abi };
    }
    template <typename D> WINRT_IMPL_AUTO(void) consume_Microsoft_UI_Xaml_Hosting_IElementCompositionPreviewStatics<D>::SetElementChildVisual(winrt::Microsoft::UI::Xaml::UIElement const& element, winrt::Microsoft::UI::Composition::Visual const& visual) const
    {
        check_hresult(WINRT_IMPL_SHIM(winrt::Microsoft::UI::Xaml::Hosting::IElementCompositionPreviewStatics)->SetElementChildVisual(*(void**)(&element), *(void**)(&visual)));
    }
    template <typename D> WINRT_IMPL_AUTO(winrt::Microsoft::UI::Composition::CompositionPropertySet) consume_Microsoft_UI_Xaml_Hosting_IElementCompositionPreviewStatics<D>::GetScrollViewerManipulationPropertySet(winrt::Microsoft::UI::Xaml::Controls::ScrollViewer const& scrollViewer) const
    {
        void* result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Microsoft::UI::Xaml::Hosting::IElementCompositionPreviewStatics)->GetScrollViewerManipulationPropertySet(*(void**)(&scrollViewer), &result));
        return winrt::Microsoft::UI::Composition::CompositionPropertySet{ result, take_ownership_from_abi };
    }
    template <typename D> WINRT_IMPL_AUTO(void) consume_Microsoft_UI_Xaml_Hosting_IElementCompositionPreviewStatics<D>::SetImplicitShowAnimation(winrt::Microsoft::UI::Xaml::UIElement const& element, winrt::Microsoft::UI::Composition::ICompositionAnimationBase const& animation) const
    {
        check_hresult(WINRT_IMPL_SHIM(winrt::Microsoft::UI::Xaml::Hosting::IElementCompositionPreviewStatics)->SetImplicitShowAnimation(*(void**)(&element), *(void**)(&animation)));
    }
    template <typename D> WINRT_IMPL_AUTO(void) consume_Microsoft_UI_Xaml_Hosting_IElementCompositionPreviewStatics<D>::SetImplicitHideAnimation(winrt::Microsoft::UI::Xaml::UIElement const& element, winrt::Microsoft::UI::Composition::ICompositionAnimationBase const& animation) const
    {
        check_hresult(WINRT_IMPL_SHIM(winrt::Microsoft::UI::Xaml::Hosting::IElementCompositionPreviewStatics)->SetImplicitHideAnimation(*(void**)(&element), *(void**)(&animation)));
    }
    template <typename D> WINRT_IMPL_AUTO(void) consume_Microsoft_UI_Xaml_Hosting_IElementCompositionPreviewStatics<D>::SetIsTranslationEnabled(winrt::Microsoft::UI::Xaml::UIElement const& element, bool value) const
    {
        check_hresult(WINRT_IMPL_SHIM(winrt::Microsoft::UI::Xaml::Hosting::IElementCompositionPreviewStatics)->SetIsTranslationEnabled(*(void**)(&element), value));
    }
    template <typename D> WINRT_IMPL_AUTO(winrt::Microsoft::UI::Composition::CompositionPropertySet) consume_Microsoft_UI_Xaml_Hosting_IElementCompositionPreviewStatics<D>::GetPointerPositionPropertySet(winrt::Microsoft::UI::Xaml::UIElement const& targetElement) const
    {
        void* result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Microsoft::UI::Xaml::Hosting::IElementCompositionPreviewStatics)->GetPointerPositionPropertySet(*(void**)(&targetElement), &result));
        return winrt::Microsoft::UI::Composition::CompositionPropertySet{ result, take_ownership_from_abi };
    }
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Microsoft::UI::Xaml::Hosting::IElementCompositionPreview> : produce_base<D, winrt::Microsoft::UI::Xaml::Hosting::IElementCompositionPreview>
    {
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Microsoft::UI::Xaml::Hosting::IElementCompositionPreviewStatics> : produce_base<D, winrt::Microsoft::UI::Xaml::Hosting::IElementCompositionPreviewStatics>
    {
        int32_t __stdcall GetElementVisual(void* element, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<winrt::Microsoft::UI::Composition::Visual>(this->shim().GetElementVisual(*reinterpret_cast<winrt::Microsoft::UI::Xaml::UIElement const*>(&element)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetElementChildVisual(void* element, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<winrt::Microsoft::UI::Composition::Visual>(this->shim().GetElementChildVisual(*reinterpret_cast<winrt::Microsoft::UI::Xaml::UIElement const*>(&element)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetElementChildVisual(void* element, void* visual) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetElementChildVisual(*reinterpret_cast<winrt::Microsoft::UI::Xaml::UIElement const*>(&element), *reinterpret_cast<winrt::Microsoft::UI::Composition::Visual const*>(&visual));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetScrollViewerManipulationPropertySet(void* scrollViewer, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<winrt::Microsoft::UI::Composition::CompositionPropertySet>(this->shim().GetScrollViewerManipulationPropertySet(*reinterpret_cast<winrt::Microsoft::UI::Xaml::Controls::ScrollViewer const*>(&scrollViewer)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetImplicitShowAnimation(void* element, void* animation) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetImplicitShowAnimation(*reinterpret_cast<winrt::Microsoft::UI::Xaml::UIElement const*>(&element), *reinterpret_cast<winrt::Microsoft::UI::Composition::ICompositionAnimationBase const*>(&animation));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetImplicitHideAnimation(void* element, void* animation) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetImplicitHideAnimation(*reinterpret_cast<winrt::Microsoft::UI::Xaml::UIElement const*>(&element), *reinterpret_cast<winrt::Microsoft::UI::Composition::ICompositionAnimationBase const*>(&animation));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetIsTranslationEnabled(void* element, bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetIsTranslationEnabled(*reinterpret_cast<winrt::Microsoft::UI::Xaml::UIElement const*>(&element), value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPointerPositionPropertySet(void* targetElement, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<winrt::Microsoft::UI::Composition::CompositionPropertySet>(this->shim().GetPointerPositionPropertySet(*reinterpret_cast<winrt::Microsoft::UI::Xaml::UIElement const*>(&targetElement)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
WINRT_EXPORT namespace winrt::Microsoft::UI::Xaml::Hosting
{
    inline auto ElementCompositionPreview::GetElementVisual(winrt::Microsoft::UI::Xaml::UIElement const& element)
    {
        return impl::call_factory<ElementCompositionPreview, IElementCompositionPreviewStatics>([&](IElementCompositionPreviewStatics const& f) { return f.GetElementVisual(element); });
    }
    inline auto ElementCompositionPreview::GetElementChildVisual(winrt::Microsoft::UI::Xaml::UIElement const& element)
    {
        return impl::call_factory<ElementCompositionPreview, IElementCompositionPreviewStatics>([&](IElementCompositionPreviewStatics const& f) { return f.GetElementChildVisual(element); });
    }
    inline auto ElementCompositionPreview::SetElementChildVisual(winrt::Microsoft::UI::Xaml::UIElement const& element, winrt::Microsoft::UI::Composition::Visual const& visual)
    {
        impl::call_factory<ElementCompositionPreview, IElementCompositionPreviewStatics>([&](IElementCompositionPreviewStatics const& f) { return f.SetElementChildVisual(element, visual); });
    }
    inline auto ElementCompositionPreview::GetScrollViewerManipulationPropertySet(winrt::Microsoft::UI::Xaml::Controls::ScrollViewer const& scrollViewer)
    {
        return impl::call_factory<ElementCompositionPreview, IElementCompositionPreviewStatics>([&](IElementCompositionPreviewStatics const& f) { return f.GetScrollViewerManipulationPropertySet(scrollViewer); });
    }
    inline auto ElementCompositionPreview::SetImplicitShowAnimation(winrt::Microsoft::UI::Xaml::UIElement const& element, winrt::Microsoft::UI::Composition::ICompositionAnimationBase const& animation)
    {
        impl::call_factory<ElementCompositionPreview, IElementCompositionPreviewStatics>([&](IElementCompositionPreviewStatics const& f) { return f.SetImplicitShowAnimation(element, animation); });
    }
    inline auto ElementCompositionPreview::SetImplicitHideAnimation(winrt::Microsoft::UI::Xaml::UIElement const& element, winrt::Microsoft::UI::Composition::ICompositionAnimationBase const& animation)
    {
        impl::call_factory<ElementCompositionPreview, IElementCompositionPreviewStatics>([&](IElementCompositionPreviewStatics const& f) { return f.SetImplicitHideAnimation(element, animation); });
    }
    inline auto ElementCompositionPreview::SetIsTranslationEnabled(winrt::Microsoft::UI::Xaml::UIElement const& element, bool value)
    {
        impl::call_factory<ElementCompositionPreview, IElementCompositionPreviewStatics>([&](IElementCompositionPreviewStatics const& f) { return f.SetIsTranslationEnabled(element, value); });
    }
    inline auto ElementCompositionPreview::GetPointerPositionPropertySet(winrt::Microsoft::UI::Xaml::UIElement const& targetElement)
    {
        return impl::call_factory<ElementCompositionPreview, IElementCompositionPreviewStatics>([&](IElementCompositionPreviewStatics const& f) { return f.GetPointerPositionPropertySet(targetElement); });
    }
}
namespace std
{
#ifndef WINRT_LEAN_AND_MEAN
    template<> struct hash<winrt::Microsoft::UI::Xaml::Hosting::IElementCompositionPreview> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Microsoft::UI::Xaml::Hosting::IElementCompositionPreviewStatics> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Microsoft::UI::Xaml::Hosting::ElementCompositionPreview> : winrt::impl::hash_base {};
#endif
}
#endif
