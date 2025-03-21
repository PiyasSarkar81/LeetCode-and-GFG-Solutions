class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        available_supp = set(supplies)
        ing_to_rec = {}
        in_degree = {}
        rec_to_ing = {}

        for i, rec in enumerate(recipes):
            recipe_ing = ingredients[i]
            rec_to_ing[rec] = recipe_ing
            in_degree[rec] = len(recipe_ing)

            for ing in recipe_ing:
                if ing not in ing_to_rec:
                    ing_to_rec[ing] = []
                ing_to_rec[ing].append(rec)

        queue = list(available_supp)
        ans = []

        while queue:
            curr = queue.pop(0)

            if curr in rec_to_ing:
                ans.append(curr)

            if curr in ing_to_rec:
                for dep_rec in ing_to_rec[curr]:
                    in_degree[dep_rec] -= 1

                    if in_degree[dep_rec] == 0:
                        queue.append(dep_rec)

        return ans