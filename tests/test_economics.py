import unittest
from scripts.economics import calculate


class EconomicsTests(unittest.TestCase):
    def test_presentation_defaults(self):
        result = calculate(3.3, 11.36, 30, 1040, 4000)
        self.assertAlmostEqual(result["monthly_electricity_saving_bdt"], 1124.64, places=2)
        self.assertAlmostEqual(result["monthly_combined_saving_bdt"], 2164.64, places=2)
        self.assertAlmostEqual(result["payback_electricity_only_months"], 4000 / 1124.64, places=5)
        self.assertAlmostEqual(result["payback_combined_months"], 4000 / 2164.64, places=5)

    def test_rejects_negative_inputs(self):
        with self.assertRaises(ValueError):
            calculate(-1, 11.36, 30, 1040, 4000)


if __name__ == "__main__":
    unittest.main()
