// Copyright (c) 2019 The Brave Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// you can obtain one at http://mozilla.org/MPL/2.0/.


#include "brave/browser/extensions/brave_browser_action_util.h"

#include <memory>
#include <string>

#include "brave/browser/ui/brave_actions/brave_action_view_controller.h"
#include "brave/browser/ui/views/brave_actions/brave_actions_container.h"
#include "brave/browser/ui/views/location_bar/brave_location_bar_view.h"
#include "brave/browser/ui/views/toolbar/brave_toolbar_view.h"
#include "chrome/browser/ui/views/frame/browser_view.h"

namespace extensions {

// static
void BraveBrowserActionUtil::ExecuteActionUI(Browser* browser,
      const std::string& extension_id,
      std::unique_ptr<std::string> relative_path) {
  BrowserView* browser_view = BrowserView::GetBrowserViewForBrowser(browser);
  // TODO(petemill): This is tied to Views hierarchy. Ideally we would
  // store a reference to BraveActionsContainer on the browser process,
  // like Chromium does, but that likely requires patching.
  BraveLocationBarView* location_bar_view =
      static_cast<BraveLocationBarView*>(
          browser_view->toolbar()->location_bar());
  BraveActionViewController* extension_controller =
      location_bar_view->GetBraveActionsContainer()
      ->GetExtensionViewController(extension_id);
  if (!extension_controller) {
    LOG(ERROR) << "Not a valid brave extension: " << extension_id;
    return;
  }
  if (relative_path) {
    extension_controller->ExecuteActionUI(*relative_path);
  } else {
    extension_controller->ExecuteAction(true);
  }
}

}  // namespace extensions
