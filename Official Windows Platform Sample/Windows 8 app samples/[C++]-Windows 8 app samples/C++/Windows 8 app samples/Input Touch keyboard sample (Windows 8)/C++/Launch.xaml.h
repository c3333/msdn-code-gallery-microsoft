//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************

//
// Launch.xaml.h
// Declaration of the Launch class
//

#pragma once

#include "pch.h"
#include "Launch.g.h"
#include "MainPage.xaml.h"

namespace SDKSample
{
    namespace TouchKeyboard
    {
        /// <summary>
        /// An empty page that can be used on its own or navigated to within a Frame.
        /// </summary>
    	[Windows::Foundation::Metadata::WebHostHidden]
        public ref class Launch sealed
        {
        public:
            Launch();
    
        protected:
            virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
        private:
            MainPage^ rootPage;
        };
    
        /// <summary>
        /// Custom Text box control derived from Textbox class.
        /// </summary>
        public ref class CustomTextBox sealed : public Windows::UI::Xaml::Controls::TextBox
        {
        public:
            CustomTextBox()
            {
                this->Background = ref new Windows::UI::Xaml::Media::SolidColorBrush(Windows::UI::Colors::Coral);
                this->BorderThickness = Windows::UI::Xaml::Thickness(1);
                this->HorizontalAlignment = Windows::UI::Xaml::HorizontalAlignment::Center;
            }
        };
    }
}
