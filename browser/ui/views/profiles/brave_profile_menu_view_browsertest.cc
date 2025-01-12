/* Copyright 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/browser/ui/views/profiles/brave_profile_menu_view.h"

#include "chrome/browser/ui/views/frame/browser_view.h"
#include "chrome/browser/ui/views/profiles/avatar_toolbar_button.h"
#include "chrome/browser/ui/views/toolbar/toolbar_view.h"
#include "chrome/test/base/in_process_browser_test.h"
#include "ui/events/base_event_utils.h"
#include "ui/events/event.h"
#include "ui/gfx/geometry/point.h"
#include "ui/views/controls/button/button.h"

class BraveProfileMenuViewTest : public InProcessBrowserTest {
 public:
  BraveProfileMenuViewTest() = default;
  ~BraveProfileMenuViewTest() override = default;

 protected:
  void OpenProfileMenuView(Browser* browser) {
    BrowserView* browser_view = BrowserView::GetBrowserViewForBrowser(browser);
    AvatarToolbarButton* button =
        browser_view->toolbar()->GetAvatarToolbarButton();
    DCHECK(button);

    ui::MouseEvent e(ui::ET_MOUSE_PRESSED, gfx::Point(), gfx::Point(),
                     ui::EventTimeForNow(), ui::EF_LEFT_MOUSE_BUTTON, 0);
    button->OnMousePressed(e);
  }

  AvatarMenu* avatar_menu() {
    ProfileMenuView* bubble = static_cast<ProfileMenuView*>(
        ProfileMenuViewBase::GetBubbleForTesting());
    DCHECK(bubble);
    return bubble->avatar_menu_.get();
  }

  const base::string16& profile_button_name() const {
    ProfileMenuView* bubble = static_cast<ProfileMenuView*>(
        ProfileMenuViewBase::GetBubbleForTesting());
    return static_cast<BraveProfileMenuView*>(bubble)
        ->current_profile_card_->GetAccessibleName();
  }

 private:
  DISALLOW_COPY_AND_ASSIGN(BraveProfileMenuViewTest);
};

IN_PROC_BROWSER_TEST_F(BraveProfileMenuViewTest, TestCurrentProfileView) {
  OpenProfileMenuView(browser());

  EXPECT_EQ(1u, avatar_menu()->GetNumberOfItems());
  const AvatarMenu::Item& item = avatar_menu()->GetItemAt(0);
  ASSERT_TRUE(!item.name.empty());
  ASSERT_EQ(item.name, profile_button_name());
}
