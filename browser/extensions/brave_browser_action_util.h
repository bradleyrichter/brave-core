// Copyright (c) 2019 The Brave Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// you can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef BRAVE_BROWSER_EXTENSIONS_BRAVE_BROWSER_ACTION_UTIL_H_
#define BRAVE_BROWSER_EXTENSIONS_BRAVE_BROWSER_ACTION_UTIL_H_

#include <memory>
#include <string>

class Browser;

namespace extensions {

class BraveBrowserActionUtil {
 public:
  static void ExecuteActionUI(
      Browser* browser,
      const std::string& extension_id,
      std::unique_ptr<std::string> relative_path);
};

}  // namespace extensions

#endif  // BRAVE_BROWSER_EXTENSIONS_BRAVE_BROWSER_ACTION_UTIL_H_
