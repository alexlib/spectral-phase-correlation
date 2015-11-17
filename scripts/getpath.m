function repo_path = getpath(repo_name);

P = pwd;

[~, ind_end] = regexpi(P, repo_name);

repo_path = P(1 : ind_end);

end