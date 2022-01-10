#include "gtest/gtest.h"
#include "../src/wordcounter.hpp"

// Test Basic functionality 
TEST(WordCounterTest, BasicMode) {
  WordCounter foo = WordCounter("party", false, false);
  ASSERT_EQ(foo.count("party Party mcparty"), 3);
}

// Test case sensitive mode
TEST(WordCounterTest, CaseSensitiveMode) {
  WordCounter foo = WordCounter("party", true, false);
  ASSERT_EQ(foo.count("party Party mcparty"), 2);
}

// Test strict mode
TEST(WordCounterTest, StrictMode) {
  WordCounter foo = WordCounter("party", false, true);
  ASSERT_EQ(foo.count("party Party mcparty"), 2);
}

//Test leading whitespace in strict mode
TEST(WordCounterTest, StrictModeLeadingWS) {
  WordCounter foo = WordCounter("party", false, true);
  ASSERT_EQ(foo.count(" party Party mcparty"), 2);
}

//Test strict/case-sensitive mode
TEST(WordCounterTest, StrictCaseMode) {
  WordCounter foo = WordCounter("party", true, true);
  ASSERT_EQ(foo.count(" party Party mcparty mcParty"), 1);
}

//Test odd unicode characters
TEST(WordCounterTest, Unicode) {
  WordCounter foo = WordCounter("pasta🍝", false, false);
  ASSERT_EQ(foo.count(" hasta la pasta🍝 party Party 🐘 mcpasta party"), 1);
}